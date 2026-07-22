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
	void Task_storage::load(std::vector<Task>& task_list)
	{
		std::vector<Task> tasks;
		char ch = 0;
		std::string description;
		status status = status::UNKOWN;
		Date created_at{ 00,"janeiro",0001 };
		Date updated_at{ 00,"janeiro",0001 };
		std::ifstream ifs{ FILE_NAME };
		int id = -1;
		if (!ifs)
			throw std::runtime_error{ "could not read " + FILE_NAME };
		// read the first char in the file, if it is not a '{' then its not the start of an object.
		while (ifs >> ch) {
			// '{'
			if (ch != '{') {
				break;
			}
			// "id":1,
			// "id"
			parser_utils::expect_string(ifs, "id");
			// ':'
			parser_utils::expect_char(ifs, ':');
			// 1
			ifs >> id;
			// ','
			parser_utils::expect_char(ifs, ',');
			// "description" : "asd",
			// "description"
			parser_utils::expect_string(ifs, "description");
			// ':'
			parser_utils::expect_char(ifs, ':');
			// "asd"
			parser_utils::expect_char(ifs, '"');
			std::getline(ifs, description,'"');
			// ','
			parser_utils::expect_char(ifs, ',');
			// "status" : "in-progress",
			// "status"
			parser_utils::expect_string(ifs, "status");
			// ':'
			parser_utils::expect_char(ifs, ':');
			// "in-progress"
			parser_utils::expect_char(ifs, '"');
			ifs >> status;
			parser_utils::expect_char(ifs, '"');
			// ','
			parser_utils::expect_char(ifs, ',');

			// "createdAt" : "20/07/2026",
			// "createdAt"
			parser_utils::expect_string(ifs, "createdAt");
			// ':'
			parser_utils::expect_char(ifs, ':');
			// "20/07/2026"
			parser_utils::expect_char(ifs, '"');
			ifs >> created_at;
			parser_utils::expect_char(ifs, '"');
			// ','
			parser_utils::expect_char(ifs, ',');

			// "updatedAt" : "20/07/2026",
			// "updatedAt"
			parser_utils::expect_string(ifs, "updatedAt");
			// ':'
			parser_utils::expect_char(ifs, ':');
			// "20/07/2026"
			parser_utils::expect_char(ifs, '"');
			ifs >> updated_at;
			parser_utils::expect_char(ifs, '"');
			// '}'
			parser_utils::expect_char(ifs, '}');

			task_list.push_back(Task{ id,description,created_at,updated_at,status });
		}
	}
}
