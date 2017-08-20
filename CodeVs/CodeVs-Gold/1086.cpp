#include <iostream>
using namespace std;
int main()
{
	int n; cin >> n;
	long long sum = 1;
	for (int i = 0; i < n; i++)
		sum = sum * (2 * n - i) / (i + 1);
	sum /= n + 1;
	cout << sum << endl;
	return 0;
}