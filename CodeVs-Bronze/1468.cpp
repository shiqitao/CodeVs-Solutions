#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main()
{
	int a, b, c;
	cin >> a >> b >> c;
	if (a + b <= c)
	{
		cout << "No answer" << endl;
		return 0;
	}
	if (a + c <= b)
	{
		cout << "No answer" << endl;
		return 0;
	}
	if (b + c <= a)
	{
		cout << "No answer" << endl;
		return 0;
	}
	double p = 0.5 * (a + b + c);
	double s = sqrt(p * (p - a) * (p - b) * (p - c));
	cout << setiosflags(ios::fixed) << setprecision(2) << s << endl;
	return 0;
}