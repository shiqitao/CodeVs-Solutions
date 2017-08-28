#include <iostream>
#include <cstring>
using namespace std;
#define MIN(x,y) x<y?x:y
int main()
{
	int n; cin >> n;
	unsigned int *weight = new unsigned int[n];
	for (int i = 0; i < n; i++)
		cin >> weight[i];
	unsigned int *sum = new unsigned int[n*n];
	for (int i = 0; i < n; i++)
	{
		unsigned int tempSum = 0;
		for (int j = i; j < n; j++)
		{
			tempSum += weight[j];
			sum[i*n + j] = tempSum;
		}
	}
	unsigned int *data = new unsigned int[n*n];
	memset(data, 255, sizeof(int)*n*n);
	for (int i = 0; i < n; i++)
		data[i*n + i] = 0;
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j + i < n; j++)
		{
			for (int k = 0; k < i; k++)
				data[j*n + j + i] = MIN(data[j*n + j + i], data[j*n + j + k] + data[(j + k + 1)*n + j + i] + sum[j*n + j + k] + sum[(j + k + 1)*n + j + i]);
		}
	}
	cout << data[n - 1] << endl;
	delete[] weight;
	delete[] sum;
	delete[] data;
	return 0;
}