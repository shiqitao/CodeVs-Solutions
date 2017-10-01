#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int k = sqrt(n);
	bool *ifPrime = new bool[k + 1];
	memset(ifPrime, 1, sizeof(bool)* k + 1);
	for (int i = 2; i < k + 1; i++)
	{
		if (!ifPrime[i]) continue;
		if (!(n % i))
		{
			cout << n / i << endl;
			delete(ifPrime);
			return 0;
		}
		int temp = k / i;
		for (int j = 2; j < temp + 1; j++)
			ifPrime[i * j] = false;
	}
	delete[] ifPrime;
}