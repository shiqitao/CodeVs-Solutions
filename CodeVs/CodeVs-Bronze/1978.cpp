#include <iostream>
using namespace std;
int main()
{
	int n; cin >> n;
	if (n == 1 || n == 2)
	{
		cout << 1 << endl;
		return 0;
	}
	int a = 1, b = 1;
	int point = 2;
	while (point != n)
	{
		point++;
		if (point % 2)
			a += b;
		else
			b += a;
	}
	if (point % 2)
		cout << a << endl;
	else
		cout << b << endl;
	return 0;
}