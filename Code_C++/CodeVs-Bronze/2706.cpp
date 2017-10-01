#include <iostream>
using namespace std;
int main()
{
	double n; cin >> n;
	if (n <= 1000)
	{
		cout << 0 << endl;
		return 0;
	}
	double sum = (n - 1000) * 0.1;
	if (n > 5000)
		sum += (n - 5000) * 0.09;
	if (n > 10000)
		sum += (n - 10000) * 0.08;
	cout << sum << endl;
	return 0;
}