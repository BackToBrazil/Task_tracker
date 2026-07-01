#include "Console_view.h"
#include <iostream>
#include <string>
using namespace task_tracker;
using std::cin, std::cout, std::string;
char Console_view::get_input() {
	// get the plain input
	char ch = '-1';
	while (true) {
		if (cin >> ch) {
			return ch;
		}
		else {
			cout << "error.\n";
			break;
		}
	}
}
void Console_view::interpret_input() {
	// makes sense of the input.
	
}
string Console_view::read_input() {
	// standard input loop.

}