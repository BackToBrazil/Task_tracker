#include "Console_io.h"
namespace task_tracker {
	std::string task_tracker::Console_io::get_line()
	{
		std::string line;
		while (true) {
			std::getline(std::cin, line);
			if (std::cin.good()) {
				return line;
			}
			else if (!std::cin.good()) {
				throw std::runtime_error{ "line not good.\n" };
			}
		}
	}
}