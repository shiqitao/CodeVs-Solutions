#include <iostream>
#include <cstring>
#include <string>
using namespace std;
const int mod = 1000000007;
int main()
{
	string str;
	long long *DP;
	while (cin >> str)
	{
		int n = str.length() + 1;
		DP = new long long[n*n];
		memset(DP, 0, sizeof(long long)*n*n);
		DP[0] = 1;
		for (int i = 1; i < n; i++)
		{
			if (str[i - 1] == 'I')
			{
				for (int j = 1; j <= i; j++)
					DP[i*n + j] = (DP[i*n + j - 1] + DP[(i - 1)*n + j - 1]) % mod;
			}
			else if (str[i - 1] == 'D')
			{
				for (int j = i - 1; j >= 0; j--)
					DP[i*n + j] = (DP[i*n + j + 1] + DP[(i - 1)*n + j]) % mod;
			}
			else
			{
				for (int k = 0; k <= i - 1; k++)
					DP[i*n] = (DP[i*n] + DP[(i - 1)*n + k]) % mod;
				for (int j = 1; j <= i; j++)
					DP[i*n + j] = DP[i*n];
			}
		}
		long long sum = 0;
		for (int i = 0; i < n; i++)
			sum = (sum + DP[(n - 1)*n + i]) % mod;
		delete[] DP;
		cout << sum << endl;
	}
	return 0;
}