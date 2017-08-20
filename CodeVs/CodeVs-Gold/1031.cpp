#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
void search(bool data[], bool ifUse[], int arrangement[], int n, int m, int num);
int main()
{
	int n; cin >> n;
	bool *data = new bool[(n + 1)*(n + 1)];
	memset(data, 0, sizeof(bool)*(n + 1)*(n + 1));
	bool *ifPrime = new bool[n + n];
	memset(ifPrime, true, sizeof(bool)* 2 * n);
	ifPrime[0] = false; ifPrime[1] = false;
	for (int i = 2; i < 2 * n; i++)
	{
		if (ifPrime[i])
		{
			for (int j = i * 2; j < 2 * n; j += i)
				ifPrime[j] = false;
		}
	}
	for (int i = 0; i < n + 1; i++)
	{
		for (int j = i + 1; j < n + 1; j++)
		{
			data[i*(n + 1) + j] = ifPrime[i + j];
			data[j*(n + 1) + i] = ifPrime[i + j];
		}
	}
	delete[] ifPrime;
	bool *ifUse = new bool[n + 1];
	memset(ifUse, false, sizeof(bool)*(n + 1));
	int *arrangement = new int[n];
	arrangement[0] = 1;
	search(data, ifUse, arrangement, n, 1, 1);
	delete[] data;
	delete[] ifUse;
	delete[] arrangement;
	return 0;
}
void search(bool data[], bool ifUse[], int arrangement[], int n, int m, int num)
{
	if (num == n)
	{
		if (data[n + 1 + arrangement[n - 1]])
		{
			for (int i = 0; i < n; i++)
				cout << arrangement[i] << " ";
			cout << endl;
			return;
		}
	}
	for (int i = 2; i <= n; i++)
	{
		if (data[m*(n + 1) + i] && !ifUse[i])
		{
			ifUse[i] = true;
			arrangement[num] = i;
			search(data, ifUse, arrangement, n, i, num + 1);
			ifUse[i] = false;
		}
	}
}