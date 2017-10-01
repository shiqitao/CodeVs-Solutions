#include <iostream>
using namespace std;
int main()
{
	int year, month;
	cin >> year >> month;
	if (year <0 || year >10000 || month<1 || month>12)
	{
		cout << "Error!";
		return 0;
	}
	int day[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (month != 2)
		cout << day[month - 1];
	else if (year % 400 == 0 || (year % 4 == 0 && year % 100))
		cout << 29;
	else
		cout << 28;
	return 0;
}