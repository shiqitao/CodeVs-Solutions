#include <iostream>
using namespace std;
int main()
{
	long long data[21] = { 0, 0, 1 };
	long long sum[21] = { 0, 1 };
	for (int i = 3; i < 21; i++)
		data[i] = (data[i - 1] + data[i - 2]) * (i - 1);
	int p; cin >> p;
	for (int i = 0; i < p; i++)
	{
		int n, m; cin >> n >> m;
		long long result = 1;
		for (int j = 0; j < (m < n - m ? m : n - m); j++)
		{
			result *= n - j;
			result /= j + 1;
		}
		result *= data[m];
		cout << result << endl;
	}
	return 0;
}