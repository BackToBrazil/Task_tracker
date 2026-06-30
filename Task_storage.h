#pragma once
#include "Task_manager.h"
#include <string>
using namespace task_tracker;

namespace task_tracker {
	class Task_storage {
		// responsible for the writting of tasks in JSON files.
		// created when Task_controller is created.
	public:
		Task_storage(){}
		void const save();
		void const load();
	private:
		const std::string FILE_NAME{ "file.JSON" };
	};
}