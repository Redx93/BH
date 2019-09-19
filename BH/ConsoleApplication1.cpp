#include <iostream>
#include "AI.h"
using namespace std;
using namespace std::placeholders;

class Action
{
public:
	int numberOfAction = 0;
	Status Attack()
	{
		if (numberOfAction >= 1)
		{
			std::cout << "Action\n" << std::endl;
			return Status::SUCCESS;
		}
		else
			return Status::FAILURE;
	}
	Status InAttackRange()
	{
		if (numberOfAction >= 1)
		{
			std::cout << "InAttackRange\n" << std::endl;
			return Status::SUCCESS;
		}
		else
			return Status::FAILURE;
	}
	bool Enemynearby()
	{
		std::cout << "Enemynearby\n" << std::endl;
		return true;
	}
	bool Roam()
	{
		std::cout << "Roam\n" << std::endl;
		return true;
	}
};



int main()
{
	Action action_b;
	Sequence sequence;
	sequence.AddChildren(Behavior(std::bind(&Action::InAttackRange, std::ref(action_b))));
	sequence.AddChildren(Behavior(std::bind(&Action::Attack, std::ref(action_b))));
	sequence.func();
	action_b.numberOfAction += 1;
	sequence.func();


	system("pause");
	return 0;
}

