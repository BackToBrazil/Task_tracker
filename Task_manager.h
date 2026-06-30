#pragma once
#include <vector>
#include "Task.h"
#include "Task_storage.h"
using namespace task_tracker;
namespace task_tracker {
	class Task_manager {
	// responsible for managing the Task objects.
	// calls Task_output for writing tasks into files.
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