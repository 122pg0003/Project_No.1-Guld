#pragma once

class SceneMgr;


class Adventurer   {
public:
	Adventurer(SceneMgr& scenemgr);
	~Adventurer();
	void Adventurer_Input();
	void Adventurer_Update();
	
//protected:
	//SceneMgr scenemgr;
private:
	SceneMgr& _scenemgr;
};
