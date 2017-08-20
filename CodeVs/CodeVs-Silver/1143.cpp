#include <iostream>
using namespace std;
void quickSort(int data[], int start, int end);
int pivotkey(int data[], int start, int end);
int main()
{
	int w, n; cin >> w >> n;
	int *data = new int[n];
	for (int i = 0; i < n; i++)
		cin >> data[i];
	quickSort(data, 0, n - 1);
	int sum = 0;
	for (int i = 0, j = n - 1; i <= j; sum++, i++)
	{
		if (data[i] + data[j] <= w) j--;
	}
	delete[] data;
	cout << sum << endl;
	return 0;
}
void quickSort(int data[], int start, int end)
{
	if (start >= end) return;
	int pivot = pivotkey(data, start, end);
	quickSort(data, start, pivot - 1);
	quickSort(data, pivot + 1, end);
}
int pivotkey(int data[], int start, int end)
{
	int key = data[start];
	int temp;
	while (start < end)
	{
		while (start < end && data[end] <= key) end--;
		temp = data[end];
		data[end] = data[start];
		data[start] = temp;
		while (start < end && data[start] >= key) start++;
		temp = data[end];
		data[end] = data[start];
		data[start] = temp;
	}
	return start;
}