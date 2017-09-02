#include <iostream>
#include <iomanip>
#include <cstring>
#include <map>
#include <algorithm>
using namespace std;
#define mod 99999997
long long numReverse = 0;
void discretization(int match[], const int n);
void mergeSort(int data[], int low, int high);
void mergeArray(int data1[], int n, int data2[], int m, int result[]);
int main()
{
	ios::sync_with_stdio(false);
	int n; cin >> n;
	int *match1 = new int[n];
	int *match2 = new int[n];
	for (int i = 0; i < n; i++)
		cin >> match1[i];
	for (int i = 0; i < n; i++)
		cin >> match2[i];
	discretization(match1, n);
	discretization(match2, n);
	map<int, int> table;
	for (int i = 0; i < n; i++)
		table[match1[i]] = i;
	for (int i = 0; i < n; i++)
		match2[i] = table[match2[i]];
	table.clear();
	mergeSort(match2, 0, n - 1);
	cout << numReverse << endl;
	return 0;
}
void discretization(int match[], const int n)
{
	int *temp = new int[n];
	memcpy(temp, match, sizeof(int)*n);
	sort(temp, temp + n);
	map<int, int> table;
	for (int i = 0; i < n; i++)
		table[temp[i]] = i;
	for (int i = 0; i < n; i++)
		match[i] = table[match[i]];
	table.clear();
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
	numReverse %= mod;
}