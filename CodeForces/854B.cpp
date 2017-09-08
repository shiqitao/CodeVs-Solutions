#include <iostream>
using namespace std;
int main()
{
	long long n, k; cin >> n >> k;
	if (k == 0)
	{
		cout << "0 0" << endl;
		return 0;
	}
	long long min = (n == k ? 0 : 1);
	long long max = (n >= 3 * k ? 2 * k : n - k);
	cout << min << " " << max << endl;
	return 0;
}