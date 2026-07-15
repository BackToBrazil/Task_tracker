#pragma once
#include <string>
#include <iostream>
namespace task_tracker {
	struct Date {
		Date(int day, std::string month, int year) : m_day{ day }, m_month{ month }, m_year{ year } {};
		int m_day;
		std::string m_month;
		int m_year;
	};
	std::ostream& operator<<(std::ostream&, const Date&);
}