#include <iostream>
#include <string>
using namespace std;
#define MAX(x,y) x>y?x:y
#define MOD 2769433
int main()
{
	string str1, str2, str3; cin >> str1 >> str2 >> str3;
	int n = str1.size() + 1;
	for (int i = 0; i < n; i++)
	{
		if (str1[i] <= 'Z') str1[i] += 32;
		if (str2[i] <= 'Z') str2[i] += 32;
		if (str3[i] <= 'Z') str3[i] += 32;
	}
	int ***DP1 = new int**[n];
	for (int i = 0; i < n; i++)
	{
		DP1[i] = new int*[n];
		for (int j = 0; j < n; j++)
		{
			DP1[i][j] = new int[n];
			memset(DP1[i][j], 0, sizeof(int)*n);
		}
	}
	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j < n; j++)
		{
			for (int k = 1; k < n; k++)
			{
				if (str1[i - 1] == str2[j - 1])
				{
					DP1[i][j][k] = MAX(DP1[i][j][k], DP1[i - 1][j - 1][k] + 1);
					if (str1[i - 1] == str3[k - 1])
					{
						DP1[i][j][k] = MAX(DP1[i][j][k], DP1[i][j - 1][k - 1] + 1);
						DP1[i][j][k] = MAX(DP1[i][j][k], DP1[i - 1][j][k - 1] + 1);
						DP1[i][j][k] = MAX(DP1[i][j][k], DP1[i - 1][j - 1][k - 1] + 1);
					}
				}
				else if (str1[i - 1] == str3[k - 1])
					DP1[i][j][k] = MAX(DP1[i][j][k], DP1[i - 1][j][k - 1] + 1);
				else if (str2[j - 1] == str3[k - 1])
					DP1[i][j][k] = MAX(DP1[i][j][k], DP1[i][j - 1][k - 1] + 1);
			}
		}
	}
	cout << DP1[n - 1][n - 1][n - 1] + 1 << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			delete[] DP1[i][j];
		delete[] DP1[i];
	}
	delete[] DP1;

	int ***DP2 = new int**[n];
	for (int i = 0; i < n; i++)
	{
		DP2[i] = new int*[n];
		for (int j = 0; j < n; j++)
		{
			DP2[i][j] = new int[n];
			memset(DP2[i][j], 0, sizeof(int)*n);
		}
	}
	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j < n; j++)
		{
			for (int k = 1; k < n; k++)
			{
				DP2[i][j][k] = DP2[i][j][k - 1] + DP2[i][j - 1][k] + DP2[i - 1][j][k]
					- DP2[i - 1][j - 1][k] - DP2[i - 1][j][k - 1] - DP2[i][j - 1][k - 1]
					+ DP2[i - 1][j - 1][k - 1];
				if (str1[i - 1] == str2[j - 1] && str1[i - 1] == str3[k - 1])
					DP2[i][j][k] += DP2[i - 1][j - 1][k - 1] + 1;
			}
		}
	}
	cout << DP2[n - 1][n - 1][n - 1] << endl;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			delete[] DP2[i][j];
		delete[] DP2[i];
	}
	delete[] DP2;
	return 0;
}