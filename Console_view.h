#pragma once
#include <string>
namespace task_tracker {
	using namespace task_tracker;
	class Console_view {
		// responsible for the console i/o
	public:
		Console_view(){}
		std::string read_input();	// standard input loop.
		char get_input();	// just get the plain user input.
		void interpret_input();	// makes sense of the input.
	private:
	};
}