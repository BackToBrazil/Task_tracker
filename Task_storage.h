#pragma once
#include "Task_manager.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdexcept>
namespace task_tracker {
	using namespace task_tracker;
	class Task_storage {
		// responsible for the i/o of tasks in JSON files.
		// its first going to load any Task from the file.JSON, then after it, pass them to the Task_manager.
	public:
		Task_storage(){}
		void save(std::vector<Task>&);	// revieces a vector and write it in the file.
		std::vector<Task> load();	// read file and return a vector with anything inside.
		void write_file();	// read the elements inside a file.
	private:
		const std::string FILE_NAME{ "file.JSON" };
		void expect_string(std::ifstream&,std::string);	// verify if the next set of chars match the string passed as argument.
		void expect_char(std::ifstream&, char);	// verify if the next char is the expected one and waste it
	};
}