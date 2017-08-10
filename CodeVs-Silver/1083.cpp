#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int m = sqrt(n * 2);
	int p = n > m*(m + 1) / 2 ? m + 1 : m;
	int q = n - p*(p - 1) / 2;
	cout << p - q + 1 << "/" << q;
	return 0;
}