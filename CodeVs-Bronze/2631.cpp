#include <iostream>
using namespace std;
int main()
{
	double a1, b1, c1, a2, b2, c2;
	cin >> a1 >> b1 >> c1 >> a2 >> b2 >> c2;
	double x, y;
	if (a1 != 0)
	{
		y = (c1 * a2 - c2 * a1) / (b1 * a2 - b2 * a1);
		x = (c1 - b1 * y) / a1;
	}
	else
	{
		y = c1 / b1;
		x = (c2 - b2 * y) / a2;
	}
	cout << "x=" << x << endl;
	cout << "y=" << y << endl;
	return 0;
}