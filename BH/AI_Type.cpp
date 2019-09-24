#include "AI_Type.h"

//void AI_runner::StartUpBehaviour()
//{
//	//Sequence sequence;
//	sequence.AddChildren(Behavior(std::bind(&Action::InAttackRange,action_b)));
//	sequence.AddChildren(Behavior(std::bind(&Action::Attack, action_b)));
//	Selector selector;
//	sequence.AddChildren(Behavior(sequence));
//	sequence.AddChildren(Behavior(std::bind(&Action::Attack, action_b)));
//	Sequence sequence2;
//	sequence2.AddChildren(Behavior(std::bind(&Action::Enemynearby, action_b)));
//	sequence2.AddChildren(Behavior(selector));
//	Selector selector2;
//	selector2.AddChildren(Behavior(sequence2));
//	selector2.AddChildren(Behavior(std::bind(&Action::Roam, action_b)));
//}
//
//void AI_runner::Execute()
//{
//	sequence.func();
//}




//#pragma once
//#include <iostream>
//#include <vector>
//using namespace std;
//
//class Selector;
//class Sequence;
//class Behavior;
//
//class Behavior
//{
//private:
//	std::string action;
//public:
//	Behavior(){}
//	Behavior(std::string action):action(action)	{}
//	virtual void addAction(std::string action) { this->action = action; };
//	void print() { std::cout << action << std::endl; }
//};
//
//class Composite : public  Behavior
//{
//protected :
//	vector<Behavior*> m_childre;
//public:
//	void AddChildren(Behavior* child)
//	{
//		m_childre.push_back(child);
//	}
//};
//class Sequence : public Composite
//{
//public:
//	void func();
//};
//
//class Selector :public Composite
//{
//public:
//	void func();
//};

//#pragma once
//#include <functional>
//#include <iostream>
//#include <vector>
//using namespace std;
//
//class Selector;
//class Sequence;
//
//enum Status
//{
//	INVALID,
//	RUNNING,
//	SUCCESS,
//	FAILURE
//};
//using ActionCallback = std::function<Status()>;
//class Behavior
//{
//private:
//	ActionCallback callback;
//public:
//	Behavior() {}
//	Behavior(ActionCallback func) :callback(func) {}
//
//	virtual void addAction(ActionCallback func)
//	{
//		this->callback = func;
//	};
//
//	Status execute()
//	{
//		/*	if (callback)
//			{
//				return	callback();
//			}
//			else
//				return false;*/
//
//		Status status;
//		//check if its empty(no function stored)
//		if (callback)
//		{
//			status = callback();
//		}
//		else
//		{	//error no leaf
//			status = Status::FAILURE;
//		}
//		return status;
//	}
//};
//template <class T> using Vector = std::vector<T>;
//template <class T> using Unique = std::unique_ptr<T>;
//
//class Composite : public  Behavior
//{
//protected:
//	//vector<std::unique_ptr<Behavior>> m_children;
//	vector<Unique<Behavior>>m_children;
//public:
//	void AddChildren(Behavior child)
//	{
//		m_children.push_back(child);
//	};
//
//	Selector* AddSelector()
//	{
//		Selector selector;
//		this->m_children.emplace_back(selector);
//		return m_children.back();
//	};
//	Sequence* AddSequence(Sequence sequence)
//	{
//		this->m_children.push_back(&sequence);
//		return &sequence;
//	};
//	Status func()
//	{
//		Status status = Status::INVALID;
//
//		for (auto c : m_children)
//		{
//			Selector* selector = dynamic_cast<Selector*>(c);
//			Sequence* sequence = dynamic_cast<Sequence*>(c);
//			if (selector)
//			{
//				status = selector->func(); // safe to call
//			}
//			else if (sequence)
//			{
//				status = sequence->func();
//			}
//			else
//			{	//we got a leaf
//				status = c->execute();
//			}
//		}
//	};
//};
//class Sequence :public Composite
//{
//public:
//	Status func();
//};
//
//class Selector :public Composite
//{
//public:
//	Status func();
//};

