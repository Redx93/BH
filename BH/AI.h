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

#pragma once
#include <functional>
#include <iostream>
#include <vector>
using namespace std;

class Selector;
class Sequence;
enum Status
{
	INVALID,
	RUNNING,
	SUCCESS,
	FAILURE
};
using ActionCallback = std::function<Status()>;
class Behavior
{
private:
	ActionCallback callback;
public:
	Behavior() {}
	Behavior(ActionCallback func) :callback(func) {}

	virtual void addAction(ActionCallback func)
	{
		this->callback = func;
	};

	Status execute()
	{
		Status status;
		//check if its empty(no function stored)
		if (callback)
		{
			status = callback();
		}
		else
		{	//error no leaf
			status = Status::FAILURE;
		}
		return status;
	}
};

//class Composite :public  Behavior
//{
//protected:
//	vector<Behavior*> m_children;
//public:
//	void AddChildren(Behavior& child)
//	{
//		m_children.emplace_back(&child);
//	}
//	/*void AddChildren(Behavior child)
//	{
//		m_children.push_back(child);
//	}*/
//	//void RemoveChild(Behavior child)
//	//{
//	//	for (size_t i = 0; i < m_children.size(); i++)
//	//	{
//	//		if (c == child)
//	//		{
//	//			m_children.erase(m_children.begin() + i);
//	//		}
//	//	}
//	//}
//};
class Sequence :public Behavior
{
private:
	vector<Behavior*> m_children;
public:
	void AddChildren(Behavior& child)
	{
		m_children.emplace_back(&child);
	}
	Status func();
};

class Selector :public Behavior
{
private:
	vector<Behavior*> m_children;
public:
	void AddChildren(Behavior& child)
	{
		m_children.emplace_back(&child);
	}
	Status func();
};

