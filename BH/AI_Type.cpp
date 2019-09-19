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
