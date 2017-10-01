#include <iostream>
using namespace std;
long long numReverse = 0;
void mergeSort(int data[], int low, int high);
void mergeArray(int data1[], int n, int data2[], int m, int result[]);
int main()
{
	int n; cin >> n;
	int *data = new int[n];
	for (int i = 0; i < n; i++)
		cin >> data[i];
	mergeSort(data, 0, n - 1);
	cout << numReverse << endl;
	delete[] data;
	return 0;
}
void mergeSort(int data[], int low, int high)
{
	if (low < high)
	{
		int mid = low + (high - low) / 2;
		mergeSort(data, low, mid);
		mergeSort(data, mid + 1, high);
		mergeArray(data + low, mid - low + 1, data + mid + 1, high - mid, data + low);
	}
}
void mergeArray(int data1[], int n, int data2[], int m, int result[])
{
	int *temp = new int[n + m];
	int i = n - 1, j = m - 1;
	while (i != -1 && j != -1)
	{
		if (data1[i] > data2[j])
		{
			numReverse += j + 1;
			temp[i + j + 1] = data1[i];
			i--;
		}
		else
		{
			temp[i + j + 1] = data2[j];
			j--;
		}
	}
	if (i != -1)
	{
		for (int k = i; k >= 0; k--)
			temp[k] = data1[k];
	}
	else
	{
		for (int k = j; k >= 0; k--)
			temp[k] = data2[k];
	}
	for (int k = 0; k < n + m; k++)
		result[k] = temp[k];
	delete[] temp;
}