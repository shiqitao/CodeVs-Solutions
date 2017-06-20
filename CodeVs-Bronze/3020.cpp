#include <iostream>
using namespace std;
int main()
{
	unsigned long long n; cin >> n;
	int m; cin >> m;
	int *data = new int[m];
	for (int i = 0; i < m; i++)
		cin >> data[i];
	for (int i = 0; i < m; i++)
	{
		if (n <= data[i])
		{
			cout << "-" << i + 1 << endl;
			return 0;
		}
		n = n - data[i];
		n *= 2;
	}
	cout << n << endl;
	delete[] data;
	return 0;
}