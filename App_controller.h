#pragma once
#include "Task_manager.h"
#include "Task_storage.h"
#include "Console_view.h"
using namespace task_tracker;
namespace task_tracker {
	class App_controller {
	// reponsible for making the bridge between the i/o layer and the storage, and task manager layer.
	// needs to first initialize the classes.
	public:

	private:
		const Task_manager& task_manager;
		const Task_storage& task_storage;
		const Console_view& console_view;
	};
}