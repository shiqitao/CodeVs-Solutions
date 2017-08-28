#include <iostream>
#include <cstring>
using namespace std;
int main()
{
	int n, k; cin >> n >> k;
	int *DP = new int[(n + 1)*(k + 1)];
	memset(DP, 0, sizeof(int)*(n + 1)*(k + 1));
	DP[0] = 1;
	for (int i = 1; i < n + 1; i++)
	{
		for (int j = 1; j < k + 1; j++)
		{
			if (i >= j)
				DP[i*(k + 1) + j] = DP[(i - j)*(k + 1) + j] + DP[(i - 1)*(k + 1) + j - 1];
		}
	}
	cout << DP[n*(k + 1) + k] << endl;
	delete[] DP;
	return 0;
}