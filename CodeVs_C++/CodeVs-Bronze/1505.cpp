#include <iostream>
#include <iomanip>
#include <string>
#include <stdlib.h>
using namespace std;
int main()
{
	string str;
	double sum = 0;
	int num = 0;
	while (cin >> str)
	{
		if (str[0] != '-' && (str[0] > '9' || str[0] < '0') && str[0] != '.') continue;
		bool ifPoint = false;
		if (str[0] == '.')
		{
			if (str.length() == 1) continue;
			else ifPoint = true;
		}
		if (str[0] == '-' && str.length() == 1) continue;
		int i;
		for (i = 1; i < str.length(); i++)
		{
			if (str[i] == '.' && ifPoint == false)
			{
				ifPoint = true;
				continue;
			}
			else if (str[i] <= '9' && str[i] >= '0') continue;
			else break;
		}
		if (i == str.length())
		{
			double temp = atof(str.c_str());
			if (temp <= 70000 && temp >= -70000)
			{
				sum += atof(str.c_str());
				num++;
			}
		}
	}
	if (num == 0)
	{
		cout << "0.00" << endl;
		return 0;
	}
	cout << setiosflags(ios::fixed) << setprecision(2) << sum / num << endl;
	return 0;
}