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
		std::ifstream ifs{ FILE_NAME };
		int id = -1;
		if (!ifs)
			throw std::runtime_error{ "could not read " + FILE_NAME };
		// read the first char in the file, if it is not a '{' then its not the start of an object.
		while (ifs >> ch) {
			if (ch != '{')
				throw std::runtime_error{ "error could not recognize object" + std::string(1,ch) };
			// "id":1,
			// "id"
			if (!verify_word(ifs, "id"))
				throw std::runtime_error{ "error could not read id" + std::string(1,ch) };
			// ':'
			ifs >> ch;
			if(ch != ':')
				throw std::runtime_error{ "error could not read id" + std::string(1,ch) };
			// 1
			ifs >> id;
			// ','
			ifs >> ch;
			if(ch != ',')
				throw std::runtime_error{ "failed the ',' check " + std::string(1,ch) };

			// "description" : "asd",
			// "description"
			if (!verify_word(ifs, "description"))
				throw std::runtime_error{ "could not read 'description'" };
			// ':'
			ifs >> ch;
			if (ch != ':')
				throw std::runtime_error{ "failed the ':' check " + std::string(1,ch) };
			// "asd"
			for (char temp; ifs >> temp && temp != '"';) {
				description += temp;
			}
			std::cout << "description: " << description << '\n';
			return tasks;
		}
		return tasks;
	}
	bool Task_storage::verify_word(std::ifstream& ifs, std::string word)
	{
		std::string temp;
		char ch = 0;
		ifs >> ch;
		if (ch != '"')
			return false;
		for (;ifs >> ch && ch != '"';) {
			temp += ch;
		}
		if (temp == word) {
			std::cout << "the '" << word << "' verification is: true\n";
			return true;
		}
		std::cout << "the '" << word << "' verification is: false\n";
		return false;
	}
	bool Task_storage::verify_word(std::ifstream& ifs, char ch)
	{
		char temp = 0;
		ifs >> temp;
		if (temp != ch)
			return false;
		return true;
	}
}
