#include <iostream>
#include <cstring>
#include <string>
using namespace std;
#define MAX(x,y) x>y?x:y
#define MOD 2769433
void repeatInitial(string str, int repeat[]);
int main()
{
	string str1, str2, str3; cin >> str1 >> str2 >> str3;
	int n1 = str1.size() + 1;
	int n2 = str2.size() + 1;
	int n3 = str3.size() + 1;
	for (int i = 0; i < n1; i++)
	{
		if (str1[i] <= 'Z') str1[i] += 32;
	}
	for (int i = 0; i < n2; i++)
	{
		if (str2[i] <= 'Z') str2[i] += 32;
	}
	for (int i = 0; i < n3; i++)
	{
		if (str3[i] <= 'Z') str3[i] += 32;
	}
	int ***DP1 = new int**[n1];
	for (int i = 0; i < n1; i++)
	{
		DP1[i] = new int*[n2];
		for (int j = 0; j < n2; j++)
		{
			DP1[i][j] = new int[n3];
			memset(DP1[i][j], 0, sizeof(int)*n3);
		}
	}
	for (int i = 1; i < n1; i++)
	{
		for (int j = 1; j < n2; j++)
		{
			for (int k = 1; k < n3; k++)
			{
				if (str1[i - 1] == str2[j - 1] && str1[i - 1] == str3[k - 1])
				{
					DP1[i][j][k] = DP1[i - 1][j - 1][k - 1] + 1;
					DP1[i][j][k] = MAX(DP1[i][j][k], DP1[i - 1][j][k]);
					DP1[i][j][k] = MAX(DP1[i][j][k], DP1[i][j - 1][k]);
					DP1[i][j][k] = MAX(DP1[i][j][k], DP1[i][j][k - 1]);
				}
				else
				{
					DP1[i][j][k] = MAX(DP1[i][j][k], DP1[i - 1][j][k]);
					DP1[i][j][k] = MAX(DP1[i][j][k], DP1[i][j - 1][k]);
					DP1[i][j][k] = MAX(DP1[i][j][k], DP1[i][j][k - 1]);
				}
			}
		}
	}
	cout << DP1[n1 - 1][n2 - 1][n3 - 1] << endl;
	for (int i = 0; i < n1; i++)
	{
		for (int j = 0; j < n2; j++)
			delete[] DP1[i][j];
		delete[] DP1[i];
	}
	delete[] DP1;

	int ***DP2 = new int**[n1];
	for (int i = 0; i < n1; i++)
	{
		DP2[i] = new int*[n2];
		for (int j = 0; j < n2; j++)
		{
			DP2[i][j] = new int[n3];
			for (int k = 0; k < n3; k++)
			{
				DP2[i][j][k] = 1;
			}
		}
	}
	int *repeat1 = new int[n1];
	int *repeat2 = new int[n2];
	int *repeat3 = new int[n3];
	repeatInitial(str1, repeat1);
	repeatInitial(str2, repeat2);
	repeatInitial(str3, repeat3);
	for (int i = 1; i < n1; i++)
	{
		for (int j = 1; j < n2; j++)
		{
			for (int k = 1; k < n3; k++)
			{
				if (str1[i - 1] == str2[j - 1] && str1[i - 1] == str3[k - 1])
				{
					DP2[i][j][k] = DP2[i - 1][j - 1][k - 1] * 2;
					if (repeat1[i - 1] != -1 && repeat2[j - 1] != -1 && repeat3[k - 1] != -1)
						DP2[i][j][k] -= DP2[repeat1[i - 1]][repeat2[j - 1]][repeat3[k - 1]];
					DP2[i][j][k] %= MOD;
				}
				else
				{
					DP2[i][j][k] = DP2[i][j][k - 1] + DP2[i][j - 1][k] + DP2[i - 1][j][k]
						- DP2[i - 1][j - 1][k] - DP2[i - 1][j][k - 1] - DP2[i][j - 1][k - 1]
						+ DP2[i - 1][j - 1][k - 1];
					DP2[i][j][k] %= MOD;
				}
			}
		}
	}
	int result = (DP2[n1 - 1][n2 - 1][n3 - 1] + MOD - 1) % MOD;
	cout << result << endl;
	for (int i = 0; i < n1; i++)
	{
		for (int j = 0; j < n2; j++)
			delete[] DP2[i][j];
		delete[] DP2[i];
	}
	delete[] DP2;
	return 0;
}
void repeatInitial(string str, int repeat[])
{
	char temp[26];
	memset(temp, -1, sizeof(char)* 26);
	int n = str.size();
	for (int i = 0; i < n; i++)
	{
		int ch = str[i] - 'a';
		repeat[i] = temp[ch];
		temp[ch] = i;
	}
}