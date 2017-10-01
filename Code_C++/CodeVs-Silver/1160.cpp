#include <iostream>
#include <cstring>
using namespace std;
int main()
{
	int n; cin >> n;
	int *data = new int[n*n];
	memset(data, 0, sizeof(int)*n*n);
	int i = n / 2, j = n / 2;
	data[i*n + j] = 1;
	int num = 1; j++;
	while (num != n*n)
	{
		data[i*n + j] = ++num;
		while (data[--i*n + j - 1] != 0)
			data[i*n + j] = ++num;
		data[i*n + j] = ++num;
		while (data[(i + 1)*n + --j] != 0)
			data[i*n + j] = ++num;
		data[i*n + j] = ++num;
		while (data[++i*n + j + 1] != 0)
			data[i*n + j] = ++num;
		data[i*n + j] = ++num;
		while (num != n*n && data[(i - 1)*n + ++j] != 0)
			data[i*n + j] = ++num;
	}
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += data[i*n + i] + data[i*n + n - 1 - i];
		for (int j = 0; j < n; j++)
			cout << data[i*n + j] << " ";
		cout << endl;
	}
	cout << --sum << endl;
	delete[] data;
	return 0;
}