#pragma once
#include <vector>
#include "Task.h"
#include "Task_storage.h"
using namespace task_tracker;
namespace task_tracker {
	class Task_manager {
	// responsible for managing the Task objects in memory.
	// its going to wait for the Task_storage to do the reading of the file.JSON,
	// then its going to recieve any Task and put them in the m_task_list.
	public:
		Task_manager(){}
		void add_task();
		void update_task();
		void delete_task();
	private:
		Task_storage m_storage;
		std::vector<Task> m_task_list{};
	};
}