#include <iostream>
using namespace std;
void quickSort(int data[], int low, int high);
int partition(int data[], int low, int high);
int main()
{
	int n; cin >> n;
	int *data = new int[n];
	for (int i = 0; i < n; i++)
		cin >> data[i];
	quickSort(data, 0, n - 1);
	for (int i = 0; i < n; i++)
		cout << data[i] << " ";
	delete[] data;
	return 0;
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
int partition(int data[], int low, int high)
{
	int key = data[low];
	int temp;
	while (low < high)
	{
		while (data[high] >= key && low < high) high--;
		temp = data[high];
		data[high] = data[low];
		data[low] = temp;
		while (data[low] <= key && low < high) low++;
		temp = data[high];
		data[high] = data[low];
		data[low] = temp;
	}
	return low;
}