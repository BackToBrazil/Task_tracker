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
		//for (auto x : task_list)
		//	ofs << "((" << x.m_id << ")(" << x.m_description << ")(" << x.m_status <<
		//	")(" << x.m_created_at << ")(" << x.m_updated_at << "))\n";

		for (auto x : task_list)
			ofs << '{' << '\n'
			<< "id" << ':' << x.m_id << ',' << '\n'
			<< "description" << ':' << x.m_description << ',' << '\n'
			<< "status" << ':' << x.m_status << ',' << '\n'
			<< "createdAt" << ':' << x.m_created_at << ',' << '\n'
			<< "updatedAt" << ':' << x.m_updated_at << '\n'
			<< '}' << '\n';
		std::cout << "save sucessful\n";
	}
	std::vector<Task> Task_storage::load()
	{
		return std::vector<Task>{};
	}
}
