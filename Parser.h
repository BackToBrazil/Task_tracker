#pragma once
#include "Command.h"
#include "Token.h"
#include <vector>
#include <stdexcept>
namespace task_tracker {
	class Parser {
	public:
		Parser(){}
		Command get_command(const std::vector<Token>&);
	};
}