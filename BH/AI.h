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
	//virtual void addAction(std::function<bool(float)> func)
	//{
	//	this->func2 = func;
	//};


	bool execute()
	{
		//check if its empty(no function stored)
		if (callback)
		{
			return	callback();
		}
		else
			return false;
	}

	//virtual void OnInitialize(){}
	//virtual void onTerminate(Status status){}
	//virtual Status Execute() = 0;
	//Status Tick()
	//{
	////	if (m_status == Status::BH_INVALID)
	////	{
	////		OnInitialize();
	////	}
	/////*	m_status = Execute();
	////	if (m_status != Status::BH_RUNNING)
	////	{
	////		onTerminate(m_status);
	////	}*/
	////	return m_status;
	//}
};

class Composite :public  Behavior
{
protected:
	vector<Behavior> m_children;
public:
	void AddChildren(Behavior child)
	{
		m_children.push_back(child);
	}
	//void RemoveChild(Behavior child)
	//{
	//	m_childre.erase(child);
	//}
};
class Sequence :public Composite
{
public:
	void func();
};

class Selector :public Composite
{
public:
	void func();
};

