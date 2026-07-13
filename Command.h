#pragma once
#include <string>
namespace task_tracker {
	class Command {
	public:
		std::string value;
		Command(std::string vv) : value{vv} {}
		void virtual execute();
	};
}