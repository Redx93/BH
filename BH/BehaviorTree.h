#pragma once
#include "AI.h"

class BT
{
private:

	vector<Sequence> sequence;
	vector<Selector> selector;
	vector<Behavior> action;
public:
	Sequence& GetSequence(){
		Sequence* temp = new Sequence();
		sequence.emplace_back(*temp);
	/*	Sequence* s = (Sequence*)&children.at(children.size());*/
		return *temp;
	}
	Selector &GetSelector() {
		Selector *temp = new Selector();
		selector.emplace_back(*temp);
		/*	Sequence* s = (Sequence*)&children.at(children.size());*/
		return *temp;
	}
	Behavior& GetAction()
	{
		Behavior* temp = new Behavior();
		action.emplace_back(*temp);
		/*	Sequence* s = (Sequence*)&children.at(children.size());*/
		return *temp;
	}
};