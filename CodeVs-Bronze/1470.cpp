#include <iostream>
using  namespace std;
void quickSort(int data[], int low, int high);
int partition(int data[], int low, int high);
int main()
{
	int n; cin >> n;
	int *data = new int[n];
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> data[i];
		sum += data[i];
	}
	quickSort(data, 0, n - 1);
	cout << sum << endl;
	cout << data[n - 1] << endl;
	cout << data[0] << endl;
	int temp = data[n - 1];
	cout << data[n - 1] << endl;
	for (int i = n - 2; i >= 0; i--)
	{
		if (data[i] != temp)
		{
			cout << data[i] << endl;
			temp = data[i];
		}
	}
	return 0;
}
void quickSort(int data[], int low, int high)
{
	int pivot;
	if (low < high)
	{
		pivot = partition(data, low, high);
		quickSort(data, low, pivot - 1);
		quickSort(data, pivot + 1, high);
	}
}
int partition(int data[], int low, int high)
{
	int pivotkey;
	pivotkey = data[low];
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