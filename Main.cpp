#include "App_controller.h"
#include "Console_view.h"
#include <iostream>
#include "Token.h"
#include "Console_io.h"
#include "Token_stream.h"
#include "Parser.h"
using namespace task_tracker;
using namespace std;

int main() {
	try {
		Console_io console_io{};
		Token_stream token_stream{};
		Parser parser{};

		cout << "start:\n";
		while (true) {
			string line = console_io.get_line();
			vector<Token> tokens = token_stream.get_tokens(line);
			Command command = parser.get_command(tokens);
			cout << command;
			cout << "\ntype something: ";
		}
	}
	catch (std::exception& e) {
		std::cerr << e.what() << '\n';
	}
}