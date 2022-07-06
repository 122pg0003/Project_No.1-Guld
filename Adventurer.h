#pragma once
#include"SceneMgr.h"



class Adventurer{
public:
	Adventurer();
	~Adventurer();
	void Adventurer_Input();
	void Adventurer_Update();
	
	protected:
	SceneMgr scenemgr;

};
