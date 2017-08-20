#include <iostream>
using namespace std;
bool ifLeapYear(int year);
int main()
{
	int data1[12] = { 31, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30 };
	int data2[12] = { 31, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30 };
	int init = 4;
	int num[7] = { 0, 0, 0, 0, 0, 0, 0 };
	int n; cin >> n;
	for (int year = 1900; year < 1900 + n; year++)
	{
		if (ifLeapYear(year))
		{
			for (int i = 0; i < 12; i++)
			{
				num[(init + data2[i]) % 7]++;
				init = (init + data2[i]) % 7;
			}
		}
		else
		{
			for (int i = 0; i < 12; i++)
			{
				num[(init + data1[i]) % 7]++;
				init = (init + data1[i]) % 7;
			}
		}
	}
	for (int i = 0; i < 7; i++)
		cout << num[i] << " ";
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