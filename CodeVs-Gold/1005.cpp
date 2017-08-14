#include <iostream>
#include <cstring>
#include <limits.h>
using namespace std;
int minNum = INT_MAX;
int n, m;
void dfs(const int data[], const int b[], int choose[], int it, int count[]);
void judge(const int data[], const int choose[]);
int main()
{
	cin >> n >> m;
	int *data = new int[n*m];
	int *b = new int[n];
	for (int i = 0; i < n*m; i++)
		cin >> data[i];
	for (int i = 0; i < n; i++)
		cin >> b[i];
	int *choose = new int[n];
	int *count = new int[m];
	memset(count, 0, sizeof(int)*m);
	dfs(data, b, choose, 0, count);
	if (minNum <= 1000) cout << minNum << endl;
	else cout << "alternative!" << endl;
	delete[] data;
	delete[] b;
	delete[] choose;
	delete[] count;
	return 0;
}
void dfs(const int data[], const int b[], int choose[], int it, int count[])
{
	if (it != n)
	{
		for (int i = 0; i <= b[it]; i++)
		{
			choose[it] = i;
			for (int j = 0; j < m; j++)
			{
				count[j] += i*data[it*m + j];
				if (minNum != INT_MAX && count[j] >= minNum / m)
				{
					for (int k = 0; k <= j; k++)
						count[k] -= i*data[it*m + k];
					return;
				}
			}
			dfs(data, b, choose, it + 1, count);
			for (int j = 0; j < m; j++)
				count[j] -= i*data[it*m + j];
		}
	}
	else judge(data, choose);
}
void judge(const int data[], const int choose[])
{
	int num = 0, temp = 0;
	for (int i = 0; i < n; i++)
		num += data[i*m] * choose[i];
	if (num == 0 || num*m >= minNum) return;
	for (int i = 1; i < m; i++)
	{
		temp = 0;
		for (int j = 0; j < n; j++)
			temp += data[j*m + i] * choose[j];
		if (temp != num) return;
	}
	minNum = num*m;
}