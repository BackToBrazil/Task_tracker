#include "Task_storage.h"
namespace task_tracker {
	void Task_storage::save(std::vector<Task>& task_list)
	{
		std::ofstream ofs{ FILE_NAME };
		if (!ofs)
			throw std::runtime_error{ "could not write file " + FILE_NAME };
		for (auto x : task_list)
			ofs << "((" << x.m_id << ")(" << x.m_description << ")(" << x.m_status <<
			")(" << x.m_created_at << ")(" << x.m_updated_at << "))\n";
		std::cout << "save sucessful\n";
	}
	std::vector<Task> Task_storage::load()
	{
		// ((1)(task1)(TODO)((15/july/2026))((15/july/2026)))
		int id;
		char ch1, ch2, ch3;
		std::string description;
		status status;
		Date createdAt{01,"janeiro",0001};
		Date updatedAt = createdAt;
		std::vector<Task> readings;
		std::ifstream ifs{ FILE_NAME };
		if(!ifs)
			throw std::runtime_error{ "could not read file " + FILE_NAME };
		while (true) {
			if (ifs.good()) {
				// id
				ifs >> ch1 >> ch2 >> id >> ch3;
				if(ch1 != '(' || ch2 != '(' || ch3 != ')')
					throw std::runtime_error{ "bad reading" + ch1 + ch2 + id + ch3};
				// description
				ifs >> ch1;
				if(ch1!='(')
					throw std::runtime_error{ "bad reading" + ch1};
				while (true) {
					ifs >> ch2;
					if (ch2 == ')')
						break;
					description += ch2;
				}
				// status
				ifs >> ch1 >> status >> ch2;
				if(ch1 != '(' || ch2 != ')')
					throw std::runtime_error{ "bad reading" + ch1 + ch2};
				// createdAt
				ifs >> ch1 >> createdAt >> ch2;
				if (ch1 != '(' || ch2 != ')')
					throw std::runtime_error{ "bad reading" + ch1 + ch2 };
				// updatedAt
				ifs >> ch1 >> updatedAt >> ch2;
				if (ch1 != '(' || ch2 != ')')
					throw std::runtime_error{ "bad reading" + ch1 + ch2 };

				readings.push_back(Task{ id,description,createdAt,updatedAt,status});
			}
			else {
				std::cout << "reading successful\n";
				return readings;
			}
			}
		}
}
