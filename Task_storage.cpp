#include "Task_storage.h"
namespace task_tracker {
	void Task_storage::save(std::vector<Task>& task_list)
	{
		std::ofstream ofs{ FILE_NAME };
		if (!ofs)
			throw std::runtime_error{ "could not write file " + FILE_NAME };
		for (auto x : task_list)
			ofs << '(' << "id:" << x.m_id << ",description:" << x.m_description << ",status:" << x.m_status <<
			",createdAt:" << x.m_created_at << ",updatedAt:" << x.m_updated_at << ')' << '\n';
		std::cout << "save sucessful\n";
	}
	std::vector<Task> Task_storage::load()
	{
		std::vector<Task> reading;
		std::ifstream ifs{ FILE_NAME };
		if(!ifs)
			throw std::runtime_error{ "could not read file " + FILE_NAME };
		

		return reading;
	}
}
