#pragma once
#include "Command.h"
#include "Add_command.cpp"
#include "Token.h"
#include <vector>
#include <stdexcept>
namespace task_tracker {
	class Parser {
		Parser(){}
		Command get_command(const std::vector<Token>&);
	};
}