#include <iostream>
using namespace std;
long long divide(long long b, long long p, long long k);
int main()
{
	long long b, p, k;
	cin >> b >> p >> k;
	long long result = divide(b, p, k);
	cout << b << "^" << p << " mod " << k << "=" << result << endl;
	return 0;
}
long long divide(long long b, long long p, long long k)
{
	if (p == 1) return b % k;
	if (p % 2) return divide(b, p / 2, k)*divide(b, p / 2, k)*b % k;
	return divide(b, p / 2, k)*divide(b, p / 2, k) % k;
}