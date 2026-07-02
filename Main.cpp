#include "App_controller.h"
using namespace task_tracker;

int main() {
	Task_manager task_manager{};
	Task_storage task_storage{};
	Console_view console_view{};

	App_controller app{ task_manager, task_storage , console_view };
	//app.run();
	return 0;
}