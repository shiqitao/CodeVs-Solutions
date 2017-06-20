#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	int m, n; cin >> m >> n;
	int temp1, temp2;
	if (m < 100) temp1 = 2;
	else if (m < 1000) temp1 = 3;
	else if (m < 10000) temp1 = 4;
	else if (m < 100000) temp1 = 5;
	if (n < 100) temp2 = 2;
	else if (n < 1000) temp2 = 3;
	else if (n < 10000) temp2 = 4;
	else if (n < 100000) temp2 = 5;
	int sum;
	int temp;
	bool ifSolution = false;
	if (temp1 == temp2)
	{
		for (int i = m; i <= n; i++)
		{
			sum = 0;
			temp = i;
			for (int j = 0; j < temp1; j++)
			{
				sum += pow(temp % 10, temp1);
				temp /= 10;
			}
			if (sum == i)
			{
				cout << sum << endl;
				ifSolution = true;
			}
		}
	}
	else
	{
		for (int i = m; i < pow(10, temp1); i++)
		{
			sum = 0;
			temp = i;
			for (int j = 0; j < temp1; j++)
			{
				sum += pow(temp % 10, temp1);
				temp /= 10;
			}
			if (sum == i)
			{
				cout << sum << endl;
				ifSolution = true;
			}
		}
		for (int k = temp1 + 1; k < temp2; k++)
		{
			for (int i = pow(10, k - 1); i < pow(10, k); i++)
			{
				sum = 0;
				temp = i;
				for (int j = 0; j < k; j++)
				{
					sum += pow(temp % 10, k);
					temp /= 10;
				}
				if (sum == i)
				{
					cout << sum << endl;
					ifSolution = true;
				}
			}
		}
		for (int i = pow(10, temp2 - 1); i <= n; i++)
		{
			sum = 0;
			temp = i;
			for (int j = 0; j < temp2; j++)
			{
				sum += pow(temp % 10, temp2);
				temp /= 10;
			}
			if (sum == i)
			{
				cout << sum << endl;
				ifSolution = true;
			}
		}
	}
	if (!ifSolution)
		cout << "No solution!" << endl;
	return 0;
}