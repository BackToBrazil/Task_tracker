#include "App_controller.h"

using namespace task_tracker;
void App_controller::run() {
	// run task_storage and task_manager methods
	// verify that a command token was typed
	// gather the specific token needs input
	Token token = Token::invalid_token;
	while (true) {
		token = m_console_view.read_input();
		if(token == Token::invalid_token){}
		if (token == Token::add_task) {
			// gather input for the name
		}
		if (token == Token::end_program){
			break;
		}
		// if(token::task_add)
		// if(token::end_program)
		// if(token::continue)
	}
}