#include <iostream>
using namespace std;
int main()
{
	int m, n;
	cin >> m >> n;
	if (m % n)
		cout << m / n + 1 << endl;
	else
		cout << m / n << endl;
	return 0;
}