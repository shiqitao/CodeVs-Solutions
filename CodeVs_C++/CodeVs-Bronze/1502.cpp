#include <iostream>
using namespace std;
bool ifLeapYear(int year);
int main()
{
	int data1[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int data2[12] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int year, month;
	cin >> year >> month;
	if (ifLeapYear(year))
		cout << data2[month - 1] << endl;
	else
		cout << data1[month - 1] << endl;
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