#include <iostream>
#include <cstring>
#include <cmath>
#include <limits.h>
using namespace std;
#define MIN(x,y) ((x)<(y)?(x):(y))
int main()
{
	int n; cin >> n; n++;
	int *distance = new int[n*n];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cin >> distance[i*n + j];
	}
	for (int k = 0; k < n; k++)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
				distance[i*n + j] = MIN(distance[i*n + j], distance[i*n + k] + distance[k*n + j]);
		}
	}
	int state = pow(2, n);
	int *DP = new int[state*n];
	memset(DP, 0x3f, sizeof(int)*state*n);
	DP[1 * n] = 0;
	for (int i = 3; i < state; i += 2)
	{
		for (int j = 0; j < n; j++)
		{
			if (i&(1 << j))
			{
				for (int k = 0; k < n; k++)
				{
					if ((i&(1 << k)) && j != k)
						DP[i*n + j] = MIN(DP[i*n + j], DP[(i - (1 << j))*n + k] + distance[k*n + j]);
				}
			}
		}
	}
	int result = INT_MAX;
	for (int i = 0; i < n; i++)
		result = MIN(result, DP[(state - 1)*n + i] + distance[i*n]);
	cout << result << endl;
	delete[] distance;
	delete[] DP;
	return 0;
}