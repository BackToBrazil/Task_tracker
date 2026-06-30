#pragma once
#include "Task_manager.h"
#include <string>
using namespace task_tracker;

namespace task_tracker {
	class Task_storage {
		// responsible for the i/o of tasks in JSON files.
		// its first going to load any Task from the file.JSON, then after it, pass them to the Task_manager.
	public:
		Task_storage(){}
		void const save();
		void const load();
	private:
		const std::string FILE_NAME{ "file.JSON" };
	};
}