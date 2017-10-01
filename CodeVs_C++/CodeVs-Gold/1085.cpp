#include <iostream>
#include <cstring>
#include <limits.h>
using namespace std;
#define MIN(x,y) x<y?x:y
#define MAX(x,y) x>y?x:y
int main()
{
	int n, m; cin >> n >> m;
	int *num = new int[n];
	for (int i = 0; i < n; i++)
		cin >> num[i];
	int *sum = new int[n*n];
	for (int i = 0; i < n; i++)
	{
		int tempSum = 0;
		for (int j = 0; j < n; j++)
		{
			tempSum += num[(i + j) % n];
			sum[i*n + j] = (tempSum % 10 + 10) % 10;
		}
	}
	int *dataMin = new int[n*n*m];
	int *dataMax = new int[n*n*m];
	memset(dataMax, 0, sizeof(int)*n*n*m);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			dataMin[i*n*m + j*m] = sum[i*n + j];
			dataMax[i*n*m + j*m] = sum[i*n + j];
			for (int k = 1; k < m; k++)
				dataMin[i*n*m + j*m + k] = INT_MAX;
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int k = 1; k < m; k++)
		{
			for (int j = k; j < n; j++)
			{
				for (int p = k - 1; p < j; p++)
				{
					dataMin[i*n*m + j*m + k] = MIN(dataMin[i*n*m + j*m + k], dataMin[i*n*m + p*m + k - 1] * sum[(i + p + 1) % n*n + (j - p - 1)]);
					dataMax[i*n*m + j*m + k] = MAX(dataMax[i*n*m + j*m + k], dataMax[i*n*m + p*m + k - 1] * sum[(i + p + 1) % n*n + (j - p - 1)]);
				}
			}
		}
	}
	int min = INT_MAX, max = 0;
	for (int i = 0; i < n; i++)
	{
		min = MIN(min, dataMin[i*n*m + (n - 1)*m + m - 1]);
		max = MAX(max, dataMax[i*n*m + (n - 1)*m + m - 1]);
	}
	delete[] num;
	delete[] sum;
	delete[] dataMin;
	delete[] dataMax;
	cout << min << endl << max << endl;
	return 0;
}