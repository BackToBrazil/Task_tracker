#pragma once
#include <vector>
#include "Task.h"
#include "Task_storage.h"
namespace task_tracker {
	using namespace task_tracker;
	class Task_manager {
	// responsible for managing the Task objects in memory.
	// its going to wait for the Task_storage to do the reading of the file.JSON,
	// then its going to recieve any Task and put them in the m_task_list.
	public:
		Task_manager(){}
		void add_task(Task);
		Task create_task();	// creates a task from console_view inputs
		void update_task();
		void input_task_list(std::vector<Task>);	// revieves task list from task_storage.
		std::vector<Task> output_task_list();	// return the task_list to task_storage.
		void delete_task();
	private:
		std::vector<Task> m_task_list;
	};
}