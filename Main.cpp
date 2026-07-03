#include "App_controller.h"
#include "Console_view.h"
#include <iostream>
#include "Token.h"
using namespace task_tracker;

int main() {
	try {
		Task_manager task_manager{};
		Task_storage task_storage{};
		Console_view console_view{};

		App_controller app{ task_manager, task_storage , console_view };
	
		std::cout << "start\n";
		Token token = console_view.get_token();
		std::cout << token;
		return 0;
	}
	catch (std::exception& e) {
		std::cerr << e.what() << '\n';
	}
}