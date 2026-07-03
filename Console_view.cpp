#include "Console_view.h"
using namespace task_tracker;
using std::cin, std::cout, std::string;
char Console_view::get_input(char terminator) {
	// get the plain input
	char ch = '0';
	if (cin >> ch) {
		if(ch != terminator)
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
	char ch;
	while (true) {
		ch = get_input(' ');
		temp += ch;
		if (temp == "add") {
			
		}
		if (temp == "end") {
			
		}
		else {
			
		}
	}
}
Token Console_view::read_input() {
	return interpret_input();
}