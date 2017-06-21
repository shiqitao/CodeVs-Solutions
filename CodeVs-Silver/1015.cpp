#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <string>
using namespace std;
int main()
{
	string str; cin >> str;
	int temp = str.find('=');
	string strLeft, strRight;
	strLeft = str.substr(0, temp);
	strRight = str.substr(temp + 1, str.size());
	if (strLeft[0] != '-')
		strLeft = '+' + strLeft + '+';
	else
		strLeft = strLeft + '+';
	if (strRight[0] != '-')
		strRight = '+' + strRight + '+';
	else
		strRight = strRight + '+';
	int temp1 = 0, temp2 = 0;
	for (int i = 0; i < strLeft.size(); i++)
	{
		if (strLeft[i] == '+' || strLeft[i] == '-')
			temp1++;
	}
	for (int i = 0; i < strRight.size(); i++)
	{
		if (strRight[i] == '+' || strRight[i] == '-')
			temp2++;
	}
	int sumLeft = 0, sumRight = 0;
	string tempStr;
	char variable;
	for (int i = 0; i < temp1; i++)
	{
		for (int j = 1; j < strLeft.size(); j++)
		{
			if (strLeft[j] == '+' || strLeft[j] == '-')
			{
				if (strLeft[j - 1] > '9')
				{
					variable = strLeft[j - 1];
					tempStr = strLeft.substr(1, j - 1);
					if (strLeft[0] == '+')
						sumLeft += atoi(tempStr.c_str());
					else
						sumLeft -= atoi(tempStr.c_str());
				}
				else
				{
					tempStr = strLeft.substr(1, j);
					if (strLeft[0] == '+')
						sumRight -= atoi(tempStr.c_str());
					else
						sumRight += atoi(tempStr.c_str());
				}
				strLeft = strLeft.substr(j, strLeft.size());
				break;
			}
		}
	}
	for (int i = 0; i < temp2; i++)
	{
		for (int j = 1; j < strRight.size(); j++)
		{
			if (strRight[j] == '+' || strRight[j] == '-')
			{
				if (strRight[j - 1] > '9')
				{
					variable = strRight[j - 1];
					tempStr = strRight.substr(1, j - 1);
					if (strRight[0] == '+')
						sumLeft -= atoi(tempStr.c_str());
					else
						sumLeft += atoi(tempStr.c_str());
				}
				else
				{
					tempStr = strRight.substr(1, j);
					if (strRight[0] == '+')
						sumRight += atoi(tempStr.c_str());
					else
						sumRight -= atoi(tempStr.c_str());
				}
				strRight = strRight.substr(j, strRight.size());
				break;
			}
		}
	}
	cout << variable << "=";
	cout << setiosflags(ios::fixed) << setprecision(3) << (float)sumRight / sumLeft << endl;
	return 0;
}