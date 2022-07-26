#pragma once
#include<unordered_map>

class Adventurer_Status {
	Adventurer_Status();
	~Adventurer_Status();
	Find(std::string);
private:
	static std::unordered_map<std::string, int[2]> _status;

};

	//map["Key1"] = 20,30,40;