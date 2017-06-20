#include <iostream>
using namespace std;
int main()
{
	int n; cin >> n;
	int *data1 = new int[n];
	int *data2 = new int[n];
	for (int i = 0; i < n; i++)
		cin >> data1[i];
	for (int i = 0; i < n; i++)
		cin >> data2[i];
	int *temp = new int[n];
	int m = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (data1[i] + data2[j] == 100)
			{
				data2[j] = 101;
				break;
			}
			if (j == n - 1)
			{
				temp[m] = i + 1;
				m++;
			}
		}
	}
	cout << m << endl;
	for (int i = 0; i < m; i++)
		cout << temp[i] << " ";
	cout << endl;
	delete[] data1;
	delete[] data2;
	return 0;
}