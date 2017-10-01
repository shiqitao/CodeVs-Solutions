#include <iostream>
using namespace std;
int main()
{
	double a, b, c; cin >> a >> b >> c;
	if (a <= 0 || b <= 0 || c <= 0)
	{
		cout << -1;
		return 0;
	}
	double x, y, z;
	if (a >= b)
	{
		if (a >= c) { x = a; y = b; z = c; }
		else { x = c; y = a; z = b; }
	}
	else
	{
		if (b >= c) { x = b; y = a; z = c; }
		else { x = c; y = a; z = b; }
	}
	if (x >= y + z)
		cout << -1;
	else
	{
		if (y*y + z*z == x*x)
			cout << 1;
		else
			cout << 0;
	}
	return 0;
}