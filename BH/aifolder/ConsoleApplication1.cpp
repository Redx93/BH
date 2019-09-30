#include <iostream>
#include "AI.h"
using namespace std;
using namespace std::placeholders;

class Action
{
public:
	bool InRange = false;
	bool Inattackrange = false;
	int distanceToPlayer = 10;
	Status Attack()
	{
		Status status = Status::INVALID;
		if (InRange)
		{
			std::cout << "Attack" << std::endl;
			status = Status::SUCCESS;
		}
		else
		{
			std::cout << "Action Failed out of range" << std::endl;
			status = Status::FAILURE;
		}
		return status;
	}
	Status InAttackRange()
	{
		Status status = Status::INVALID;
		if (Inattackrange)
		{
			std::cout << "InAttackRange" << std::endl;
			status = Status::SUCCESS;
		}
		else
		{
			std::cout << "InAttackRange Failed out of Range" << std::endl;
			status =  Status::FAILURE;
		}
		return status;
	}
	Status Enemynearby()
	{
		Status status = Status::INVALID;
		if (InRange)
		{
			std::cout << "Enemy is nearby" << std::endl;
			status = Status::SUCCESS;
		}
		else
		{
			std::cout << "No one is nearby" << std::endl;
			status = Status::FAILURE;
		}
		return status;
	}
	Status Roam()
	{
		std::cout << "Roam around like youre all alone" << std::endl;
		return Status::SUCCESS;
	}
	Status Chase()
	{
		Status status = Status::INVALID;
		std::cout << "Chase Player" << std::endl;
		status = Status::SUCCESS;
	
		return status;
	}
};

//class Simple
//{
//private:
//	Action action_b;
//	Selector selector;
//public:
//	Simple() {
//		//Selector selector;
//		Sequence sequence;
//
//		selector.AddChildren(sequence);
//		Behavior roam = Behavior(std::bind(&Action::Roam, std::ref(action_b)));
//		selector.AddChildren(roam);
//
//		Behavior enemynear = Behavior(std::bind(&Action::Enemynearby, std::ref(action_b)));
//		sequence.AddChildren(enemynear);
//		Selector selector2;
//		sequence.AddChildren(selector2);
//		Sequence sequence2;
//
//		selector2.AddChildren(sequence2);
//		Behavior chase = Behavior(std::bind(&Action::Chase, std::ref(action_b)));
//		selector2.AddChildren(chase);
//
//		Behavior inrange = Behavior(std::bind(&Action::InAttackRange, std::ref(action_b)));
//		Behavior attack = Behavior(std::bind(&Action::Attack, std::ref(action_b)));
//		sequence2.AddChildren(inrange);
//		sequence2.AddChildren(attack);
//	}
//	void callfunction() {
//
//		selector.func();
//		action_b.InRange = true;
//		std::cout << "*************" << std::endl;
//		selector.func();
//	}
//};

int main()
{
	Action action_b;
	//BT bt;
	//auto selector = bt.GetRoot();
	////auto selector = bt.AddChildren(Selector());
	//auto sequence = selector->AddSequence();
	//selector->AddChildren(Behavior(std::bind(&Action::Roam, std::ref(action_b))));
	//sequence->AddChildren(Behavior(std::bind(&Action::Enemynearby, std::ref(action_b))));
	//auto selector2 = sequence->AddSelector(Selector());
	//auto sequence2 = selector2->AddSequence(Sequence());
	//selector2->AddChildren(Behavior(std::bind(&Action::Chase, std::ref(action_b))));
	//
	//sequence2->AddChildren(Behavior(std::bind(&Action::InAttackRange, std::ref(action_b))));
	//sequence2->AddChildren(Behavior(std::bind(&Action::Attack, std::ref(action_b))));

	Selector selector;// = new Selector();
	Sequence sequence;

	selector.AddChildren(sequence);
	Behavior roam = Behavior(std::bind(&Action::Roam, std::ref(action_b)));
	selector.AddChildren(roam);
	
	Behavior enemynear = Behavior(std::bind(&Action::Enemynearby, std::ref(action_b)));
	sequence.AddChildren(enemynear);
	Selector selector2;
	sequence.AddChildren(selector2);
	Sequence sequence2;

	selector2.AddChildren(sequence2);
	Behavior chase = Behavior(std::bind(&Action::Chase, std::ref(action_b)));
	selector2.AddChildren(chase);

	Behavior inrange = Behavior(std::bind(&Action::InAttackRange, std::ref(action_b)));
	Behavior attack = Behavior(std::bind(&Action::Attack, std::ref(action_b)));
	sequence2.AddChildren(inrange);
	sequence2.AddChildren(attack);

	
	selector.func();
	action_b.InRange = true;
	std::cout << "*************" << std::endl;
	selector.func();

	//Simple s;
	//s.callfunction();
	system("pause");
	return 0;
}

