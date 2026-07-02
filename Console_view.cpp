#include "Console_view.h"
using namespace task_tracker;
using std::cin, std::cout, std::string;
char Console_view::get_input() {
	// get the plain input
	char ch = '0';
	if (cin >> ch) {
		return ch;
	}
	else if (cin.eof()) {
		return ch;
	}
	else {
		cout << "error.\n";
		return ch;
	}
}
Token Console_view::interpret_input() {
	// makes sense of the input.
	string temp;
	while (true) {
		temp += get_input();
		if (temp == "add") {
			return Token::add_task;
		}
		if (temp == "end") {
			return Token::end_program;
		}
	}
}
Token Console_view::read_input() {
	// standard input loop.
	cout << "start:\n";
	Token token = interpret_input();
	return token;
}