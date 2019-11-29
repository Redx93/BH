#include "AI.h"

/*  A sequence will visit each child in order,
starting with the first, and when that succeeds will call the second,
and so on down the list of children. 
If any child fails it will immediately return failure to the parent.
If the last child in the sequence succeeds,
then the sequence will return success to its parent.
*/

Status Sequence::func()
{
	//Set a default value on status
	Status status = Status::INVALID;

	for (size_t i = 0; i < m_children.size() && 
		status != Status::FAILURE &&// if fail dont go further down
		status != Status::RUNNING &&
		status != Status::WAIT	; i++) //if Running, we are not done with the task til its succeeded
	{
		Selector* selector = dynamic_cast<Selector*>(m_children[i]);
		Randomize* random = dynamic_cast<Randomize*>(m_children[i]);
		if (selector)
		{
			status = selector->func(); // safe to call
		}
		else if (random)
		{
			status = random->func(); // safe to call
		}
		else {//we got a leaf

			status = m_children[i]->execute();
		}

	}
	return status;
}



/*Where a sequence is an AND, 
requiring all children to succeed to return a success, 
a selector will return a success if any of its children succeed and not process any further children.
It will process the first child, and if it fails will process the second,
and if that fails will process the third, until a success is reached, 
at which point it will instantly return success. It will fail if all children fail.*/

Status Selector::func()
{
	Status status = Status::INVALID;
	for (size_t i = 0; i < m_children.size() &&
		status != Status::SUCCESS &&// if we succeed lets return it
		status != Status::RUNNING &&
		status != Status::WAIT	; i++) //if Running, we are not done with the task til its succeeded
	{
		Sequence* sequence = dynamic_cast<Sequence*>(m_children[i]);
		//Randomize* random = dynamic_cast<Randomize*>(m_children[i]);
		if (sequence)
		{
			status = sequence->func(); // safe to call
		}
		//else if (random)
		//{
		//	status = random->func(); // safe to call
		//}
		else {//we got a leaf

			status = m_children[i]->execute();
		}

	}
	return status;
}

Status Randomize::func()
{
	/*	choses one out of the children to execute	*/

	/*if we succeed the action*/
	if(randomize != Status::SUCCESS)
	{
		Sequence* sequence = dynamic_cast<Sequence*>(m_children[index]);
		Selector* selector = dynamic_cast<Selector*>(m_children[index]);
		if (sequence)
		{
			randomize = sequence->func();
		}
		else if (selector)
		{
			randomize = selector->func();
		}
		else {

			randomize = m_children[index]->execute();
		}
	}
	if (randomize == Status::SUCCESS)
	{
		/*pick another random action to execute*/
		index = rand() % m_children.size();
		randomize = Status::RUNNING;// its still running 
	}
	
	return randomize;
}
