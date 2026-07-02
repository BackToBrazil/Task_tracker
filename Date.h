#pragma once
#include <string>
#include <iostream>
namespace task_tracker {
	struct Date {
		int day;
		std::string month;
		int year;
	};
	std::ostream& operator<<(std::ostream&, const Date&);
}