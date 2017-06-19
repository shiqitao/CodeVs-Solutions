#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	double s, v2, v1;
	cin >> s >> v2 >> v1;
	double a = v2 + (v1 - v2) / (v1 + v2) * (v2 - v1) - v1*v1 / v2;
	double b = s - s * v1 / v2;
	double t1 = b / a;
	double t2 = t1 * (v1 - v2) / (v1 + v2);
	double t3 = (s - t1 * v1 - t2 * v2) / v2;
	double result = t1 + t2 + t3;
	cout << setiosflags(ios::fixed) << setprecision(2) << result << endl;
	return 0;
}