#include <iostream>
using namespace std;
bool ifLeapYear(int year);
int main()
{
	int n; cin >> n;
	if (ifLeapYear(n))
		cout << 366 << endl;
	else
		cout << 365 << endl;
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