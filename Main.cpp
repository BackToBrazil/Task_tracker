#include <iostream>
#include "App_controller.h"
#include "Token.h"
#include "Console_io.h"
#include "Token_stream.h"
#include "Parser.h"
#include "Task_storage.h"
using namespace task_tracker;
using namespace std;

int main() {
	//TODO: WHEN ENTERING WHITESPACE OR NEWLINE AS FIRST CHAR THE PROGRAM CRASHES
	//TODO: WHEN ENTERING STRANGE INPUT ('%' "asdsd") PROGRAM CRASHES
	//TODO: task_storage.load() is only reading one task
	try {
		Console_io console_io{};
		Token_stream token_stream{};
		Parser parser{};
		Task_manager task_manager{};
		Task_storage task_storage{};

		cout << "start:\n";
		//std::vector<Task> my_task_list;
		//my_task_list = task_storage.load();
		//cout << "ouput:\n";
		//for (auto x : my_task_list)
		//	cout << x << '\n';
		while (true) {
			string line = console_io.get_line();
			vector<Token> tokens = token_stream.get_tokens(line);
			Command command = parser.get_command(tokens);
			if (command.command_type == Command_type::add) {
				task_manager.add_task(command);
			}
			for (auto x : task_manager.m_task_list)
				cout << x << '\n';

			task_storage.save(task_manager.m_task_list);
			cout << "\ntype something: ";
		}
	}
	catch (std::exception& e) {
		std::cerr << e.what() << '\n';
	}
}