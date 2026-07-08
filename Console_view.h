#pragma once
#include <string>
#include <iostream>
#include <exception>
#include "Token.h"
namespace task_tracker {
	using namespace task_tracker;
	class Console_view {
		// responsible for the console i/o
	public:
		Console_view(){}
		Token get_token();
	private:
		char get_input();	// just get the plain user input.
		std::string get_task_name(char);
		std::string get_command(char, char);
	};
}