#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
int main()
{
	int n; cin >> n;
	if (n == 2 || n == 3)
	{
		cout << "\\t";
		return 0;
	}
	int sqrtn = sqrt(n);
	bool *ifPrime = new bool[sqrtn + 1];
	memset(ifPrime, true, sizeof(bool)* (sqrtn + 1));
	for (int i = 2; i <= sqrtn; i++)
	{
		if (ifPrime[i])
		{
			int k = i * 2;
			while (k <= sqrtn)
			{
				ifPrime[k] = false;
				k += i;
			}
		}
	}
	for (int i = 2; i <= sqrtn; i++)
	{
		if (ifPrime[i] && n % i == 0)
		{
			cout << "\\n";
			return 0;
		}
	}
	cout << "\\t";
	return 0;
}