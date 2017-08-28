#include <iostream>
#include <cstring>
using namespace std;
int main()
{
	int n, k; cin >> n >> k;
	int *data = new int[(n + 1)*(k + 1)];
	memset(data, 0, sizeof(int)*(n + 1)*(k + 1));
	data[0] = 1;
	for (int i = 1; i < n + 1; i++)
	{
		for (int j = 1; j < k + 1; j++)
		{
			if (i >= j)
				data[i*(k + 1) + j] = data[(i - j)*(k + 1) + j] + data[(i - 1)*(k + 1) + j - 1];
		}
	}
	cout << data[n*(k + 1) + k] << endl;
	delete[] data;
	return 0;
}