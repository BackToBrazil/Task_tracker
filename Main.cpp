#include "App_controller.h"
#include "Console_view.h"
#include <iostream>
#include "Token.h"
#include "Console_io.h"
using namespace task_tracker;
using namespace std;

int main() {
	try {
		Console_io console_io{};
		cout << "start:\n";
		cout << console_io.get_line();
	}
	catch (std::exception& e) {
		std::cerr << e.what() << '\n';
	}
}