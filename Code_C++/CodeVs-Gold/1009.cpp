#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <queue>
using namespace std;
int main()
{
	int num[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	string str; cin >> str;
	int strl = str.length();
	for (int i = 0; i < strl; i++)
		num[str[i] - '0']++;
	int n; cin >> n;
	int temp1, temp2;
	bool trace[10][10];
	memset(trace, 0, sizeof(bool)* 100);
	for (int i = 0; i < n; i++)
	{
		cin >> temp1 >> temp2;
		trace[temp1][temp2] = true;
	}
	queue<int> q;
	int temp;
	for (int i = 0; i < 10; i++)
	{
		trace[i][i] = true;
		for (int j = 0; j < 10; j++)
		{
			if (trace[i][j]) q.push(j);
		}
		while (!q.empty())
		{
			temp = q.front();
			for (int j = 0; j < 10; j++)
			{
				if (trace[temp][j] && !trace[i][j])
				{
					trace[i][j] = true;
					q.push(j);
				}
			}
			q.pop();
		}
	}
	unsigned long long int sum = 1;
	int change[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
			change[i] += trace[i][j];
	}
	for (int i = 0; i < 10; i++)
		sum *= pow(change[i], num[i]);
	cout << sum << endl;
	return 0;
}