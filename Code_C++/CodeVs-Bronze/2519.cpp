#include <iostream>
using namespace std;
bool ifLeapYear(int year);
int main()
{
	int year, month, day;
	cin >> year >> month >> day;
	int sum = 0;
	if (month <= 2)
	{
		for (int i = year; i < 2008; i++)
			sum += 365 + ifLeapYear(i);
	}
	else
	{
		for (int i = year + 1; i <= 2008; i++)
			sum += 365 + ifLeapYear(i);
	}
	if (month > 8)
	{
		for (int i = 8; i < month; i++)
			sum -= 30 + (i + 1) % 2;
	}
	else if (month < 8)
	{
		for (int i = month; i < 8; i++)
			sum += 30 + i % 2;
	}
	if (month <= 2)
		sum -= 1;
	sum -= day - 8;
	cout << sum << endl;
	return 0;
}
bool ifLeapYear(int year)
{
	if (year % 4) return false;
	else if (year % 100) return true;
	else
	{
		if (year % 400) return false;
		else return true;
	}
}