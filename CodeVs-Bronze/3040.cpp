#include <iostream>
using namespace std;
int main()
{
	unsigned long long k; cin >> k;
	unsigned long long n = 8;
	while (n % 3 != 2 || n % 5 != 3 || n % 7 != 2)
		n++;
	n += (k - 1) * 3 * 5 * 7;
	cout << n << endl;
	return 0;
}