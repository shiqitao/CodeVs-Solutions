#include <iostream>
#include <cstring>
#include <limits.h>
using namespace std;
int main()
{
	int n; cin >> n;
	int *data = new int[n*n];
	for (int i = 0; i < n*n; i++)
		cin >> data[i];

	int *u = new int[n];
	bool *v = new bool[n];
	memset(v, true, sizeof(bool)*n);

	int num = 1;
	u[0] = 0;
	v[0] = false;

	int result = 0;
	while (num != n)
	{
		int min = INT_MAX;
		int temp = -1;
		for (int i = 0; i < num; i++)
		{
			for (int j = 1; j < n; j++)
			{
				if (v[j] && data[u[i] * n + j] < min)
				{
					min = data[u[i] * n + j];
					temp = j;
				}
			}
		}
		u[num] = temp;
		v[temp] = false;
		num++;
		result += min;
	}
	cout << result << endl;
	delete[] data;
	delete[] u;
	delete[] v;
	return 0;
}