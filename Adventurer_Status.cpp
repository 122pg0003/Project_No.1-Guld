#include"DxLib.h"
#include"Adventurer_Status.h"

std::unordered_map<std::string, int>    Adventurer_Status::_status;

Adventurer_Status::Adventurer_Status() {

	//std::unordered_map<std::string, int[3]> _status = {
	//{ 20,30,40,"Key1" }
	//};

	//int neme [3] = {20,20,20};
	//_status["Key1"] = neme;
	_status["Key1"] = 20,20,20;
	_status["Key2"] = 20, 20, 20;
	//_status["Key2"] = { 20,20,20 };


}

Adventurer_Status::~Adventurer_Status() {

}


   int Adventurer_Status::Find(std::string status) {
	auto itr = _status.find(status);
	return itr->second;

}
