#include <iostream>
#include <cstring>
using namespace std;
int main()
{
	int n = 20;
	long long *DP = new long long[n*n];
	memset(DP, 0, sizeof(long long)*n*n);
	DP[0] = 1;
	for (int j = 0; j < n; j++)
	{
		if (j % 2)
		{
			for (int k = 1; k <= j; k++)
				DP[j*n + k] += DP[j*n + k - 1] + DP[(j - 1)*n + k - 1];
		}
		else
		{
			for (int k = j - 1; k >= 0; k--)
				DP[j*n + k] += DP[j*n + k + 1] + DP[(j - 1)*n + k];
		}
	}

	long long *sum = new long long[n];
	memset(sum, 0, sizeof(long long)*n);
	sum[0] = 1;
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j <= i; j++)
			sum[i] += DP[i*n + j];
		sum[i] *= 2;
	}
	int P; cin >> P;
	delete[] DP;
	for (int i = 0; i < P; i++)
	{
		int m; cin >> m >> m;
		cout << i + 1 << " " << sum[m - 1] << endl;
	}
	delete[] sum;
	return 0;
}