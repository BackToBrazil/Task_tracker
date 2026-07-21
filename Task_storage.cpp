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
		std::string description;
		std::string status;
		std::ifstream ifs{ FILE_NAME };
		int id = -1;
		if (!ifs)
			throw std::runtime_error{ "could not read " + FILE_NAME };
		// read the first char in the file, if it is not a '{' then its not the start of an object.
		while (ifs >> ch) {
			// '{'
			if (ch != '{')
				throw std::runtime_error{ "expected '{' but caught '" + std::string(1,ch) + "'" };
			// "id":1,
			// "id"
			expect_string(ifs, "id");
			// ':'
			expect_char(ifs, ':');
			// 1
			ifs >> id;
			std::cout << "id: " << id << '\n';
			// ','
			expect_char(ifs, ',');
			// "description" : "asd",
			// "description"
			expect_string(ifs, "description");
			// ':'
			expect_char(ifs, ':');
			// "asd"
			expect_char(ifs, '"');
			std::getline(ifs, description,'"');
			std::cout << "description: " << description << '\n';
			// ','
			expect_char(ifs, ',');
			// "status" : "in-progress",
			// "status"
			expect_string(ifs, "status");
			// ':'
			expect_char(ifs, ':');
			// "in-progress"
			expect_char(ifs, '"');
			std::getline(ifs, status, '"');
			std::cout << "status: " << status << '\n';
			// ','
			expect_char(ifs, ',');
			return tasks;
		}
		return tasks;
	}
	void Task_storage::expect_string(std::ifstream& ifs, std::string word)
	{
		std::string temp;
		char ch = 0;
		expect_char(ifs, '"');
		if (std::getline(ifs, temp, '"')) {
			if (temp == word) {
				//std::cout << "expect_string successful: " + temp + '\n';
				return;
			}
			else
				throw std::runtime_error{ "expected '" + word + " but caught '" + temp + "'"};
		}
		throw std::runtime_error{ "could not read '" + word + "'" };
	}
	void Task_storage::expect_char(std::ifstream& ifs, char ch)
	{
		char temp = ifs.peek();
		if (isspace(temp))
			ifs.ignore();
		if (ifs.get(temp)) {
			if (temp != ch)
				throw std::runtime_error{ "expected '" + std::string(1,ch) + "' but caught '" + std::string(1,temp) + "'"};
		}
		else {
			throw std::runtime_error{ "could not read '" + std::string(1,ch) + "'"};
		}
	}	
}
