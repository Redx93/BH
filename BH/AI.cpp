#include "AI.h"
//#include "AI.h"
//
//void Sequence::func()
//{
//	for (auto c : m_childre)
//	{
//		//Selector* se = dynamic_cast<Selector*>(c);
//		//if (se)
//		//{
//		//	se->func(); // safe to call
//		//}
//		//else
//			c->print();
//	}
//}
//
//void Selector::func()
//{
//	for (auto c : m_childre)
//	{
//		Sequence* se = dynamic_cast<Sequence*>(c);
//		if (se)
//		{
//
//			se->func(); // safe to call
//		}
//		else
//			c->print();
//	}
//}

void Sequence::func()
{
	for (auto c : m_children)
	{
		if (Selector * se = dynamic_cast<Selector*>(&c))
		{
			se->func(); // safe to call
		}
		else
			c.execute();
	}
}

void Selector::func()
{
	for (auto c : m_children)
	{
		if (Sequence * se = dynamic_cast<Sequence*>(&c))
		{
			se->func(); // safe to call
		}
		else
			c.execute();
	}
}
