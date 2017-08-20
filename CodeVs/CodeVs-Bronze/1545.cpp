#include <iostream>
using namespace std;
int partition(int data[], int low, int high);
void quickSort(int data[], int low, int high);
int main()
{
	int n; cin >> n;
	int *data = new int[n];
	for (int i = 0; i < n; i++)
		cin >> data[i];
	quickSort(data, 0, n - 1);
	for (int i = 0; i < n; i++)
		cout << data[i] << endl;
	return 0;
}
int partition(int data[], int low, int high)
{
	int pivotkey = data[low];
	int temp;
	while (low < high)
	{
		while (low < high && data[high] >= pivotkey)
			high--;
		temp = data[low];
		data[low] = data[high];
		data[high] = temp;
		while (low < high && data[low] <= pivotkey)
			low++;
		temp = data[low];
		data[low] = data[high];
		data[high] = temp;
	}
	return low;
}
void quickSort(int data[], int low, int high)
{
	if (low < high)
	{
		int pivot = partition(data, low, high);
		quickSort(data, low, pivot - 1);
		quickSort(data, pivot + 1, high);
	}
}