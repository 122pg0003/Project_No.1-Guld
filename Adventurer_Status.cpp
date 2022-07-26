#include"Adventurer_Status.h"

Adventurer_Status::Adventurer_Status() {

	map["Key1"] = 20, 30, 40;
	map["Key2"] = 20, 30, 40;

}

Adventurer_Status::Find(std::string status) {
	auto itr = _status.find(status);
	return itr->second;

}
