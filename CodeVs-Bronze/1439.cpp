#include <iostream>
#include <cstring>
using namespace std;
int main()
{
	int L, R;
	cin >> L >> R;
	bool *ifPrime = new bool[R];
	memset(ifPrime, true, sizeof(bool)* R);
	ifPrime[0] = false;
	ifPrime[1] = false;
	for (int i = 2; i < R; i++)
	{
		if (ifPrime[i])
		{
			int k = i * 2;
			while (k < R)
			{
				ifPrime[k] = false;
				k += i;
			}
		}
	}
	int numPrime = 0;
	for (int i = L + 1; i < R; i++)
	{
		if (ifPrime[i])
			numPrime++;
	}
	cout << numPrime << endl;
	return 0;
}