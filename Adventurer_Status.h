#pragma once
#include<unordered_map>

class Adventurer_Status {
	Adventurer_Status();
	~Adventurer_Status();
	int Find(std::string status);
private:
	static std::unordered_map<std::string, int[3]> _status;
   	

};

	//map["Key1"] = 20,30,40;