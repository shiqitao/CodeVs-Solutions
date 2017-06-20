#include <iostream>
#include <iomanip>
using namespace std;
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
	cout << setiosflags(ios::fixed) << setprecision(6) << (double)sum / n << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = n - 1; j > i; j--)
		{
			if (data[j] < data[j - 1])
			{
				int temp = data[j];
				data[j] = data[j - 1];
				data[j - 1] = temp;
			}
		}
	}
	if (n % 2)
		cout << setiosflags(ios::fixed) << setprecision(6) << (double)data[n / 2] << endl;
	else
		cout << setiosflags(ios::fixed) << setprecision(6) << (data[n / 2] + data[n / 2 - 1]) / 2.0 << endl;
	delete[] data;
	return 0;
}