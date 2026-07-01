#include "App_controller.h"
#include "Console_view.h"
#include <string>
using namespace task_tracker;
void App_controller::run() {
	// run task_storage and task_manager methods
	std::string token;	// Token token;
	while (true) {
		token = m_console_view.read_input();
		// if(token::task_add)
		// if(token::end_program)
		// if(token::continue)
	}
}