#include "App_controller.h"
#include "Console_view.h"
#include <iostream>
#include "Token.h"
#include "Console_io.h"
#include "Token_stream.h"
using namespace task_tracker;
using namespace std;

int main() {
	try {
		Console_io console_io{};
		Token_stream token_stream{};

		cout << "start:\n";
		string line = console_io.get_line();
		vector<Token> tokens = token_stream.get_tokens(line);
		
	}
	catch (std::exception& e) {
		std::cerr << e.what() << '\n';
	}
}