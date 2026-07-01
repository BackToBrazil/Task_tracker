#pragma once
#include "Task_manager.h"
#include "Task_storage.h"
#include "Console_view.h"
#include "Task.h"
namespace task_tracker {
	using namespace task_tracker;
	class App_controller {
	// reponsible for making the bridge between the i/o layer and the storage, and task manager layer.
	// needs to first initialize the classes.
	public:
		App_controller(const Task_manager& task_manager, const Task_storage& task_storage, Console_view& console_view) : m_task_manager{task_manager},
			m_task_storage{ task_storage }, m_console_view{console_view} {}
		void run();
	private:
		const Task_manager& m_task_manager;
		const Task_storage& m_task_storage;
		Console_view& m_console_view;
	};
}