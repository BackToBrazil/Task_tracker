#pragma once
#include <string>
#include <iostream>
namespace task_tracker {
	class Console_io {
	public:
		Console_io() {};
		std::string get_line();
	};
}