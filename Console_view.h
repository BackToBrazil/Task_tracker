#pragma once
#include <string>
#include <iostream>
#include "Token.h"
namespace task_tracker {
	using namespace task_tracker;
	class Console_view {
		// responsible for the console i/o
	public:
		Console_view(){}
		Token read_input();	// standard input loop.
		// fill_from_file();
		// recover_fail_input();
		Token interpret_input();	// makes sense of the input.
		void send_message(std::string);
	private:
		char get_input(char);	// just get the plain user input.
	};
}