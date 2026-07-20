#include "Task_storage.h"
namespace task_tracker {
	//{
	//		"id":1,
	//		"description" : "asd",
	//		"status" : "in-progress",
	//		"createdAt" : "20/07/2026",
	//		"updatedAt" : "20/07/2026"
	//}
	void Task_storage::save(std::vector<Task>& task_list)
	{
		std::ofstream ofs{ FILE_NAME };
		if (!ofs)
			throw std::runtime_error{ "could not write file " + FILE_NAME };
		
		for (auto x : task_list)
			ofs << '{' << '\n'
			<< '"' << "id" << '"' << ':' << x.m_id << ',' << '\n'
			<< '"' << "description" << '"' << ':' << '"' << x.m_description << '"' << ',' << '\n'
			<< '"' << "status" << '"' << ':' << '"' << x.m_status << '"' << ',' << '\n'
			<< '"' << "createdAt" << '"' << ':' << '"' << x.m_created_at << '"' << ',' << '\n'
			<< '"' << "updatedAt" << '"' << ':' << '"' << x.m_updated_at << '"' << '\n'
			<< '}' << '\n';
		std::cout << "save sucessful\n";
	}
	std::vector<Task> Task_storage::load()
	{
		std::vector<Task> tasks;
		char ch = 0;
		std::string word;
		std::ifstream ifs{ FILE_NAME };
		int id = -1;
		if (!ifs)
			throw std::runtime_error{ "could not read " + FILE_NAME };
		// read the first char in the file, if it is not a '{' then its not the start of an object.
		while (ifs >> ch) {
			if (ch != '{')
				throw std::runtime_error{ "error could not read " + ch };
			// verify if the next line starts with a '"' then checks to see if its the id.
			ifs >> ch;
			if(ch != '"')
				throw std::runtime_error{ "error could not read " + ch };
			for (;ifs >> ch && ch != '"';) {
				word += ch;
			}
			if (word == "id") {
				ifs >> id;
			}
			// check the ','
			ifs >> ch;
			if(ch != ',')
				throw std::runtime_error{ "error could not read " + ch };

			return tasks;
		}
		return tasks;
	}
}
