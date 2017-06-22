#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
double a, b, c, d;
double f(double x);
int main()
{
	cin >> a >> b >> c >> d;
	int answer = 0;
	double f1, f2;
	for (double i = -100; i < 100; i += 1)
	{
		f1 = f(i); f2 = f(i + 1);
		if (f1 * f2 == 0)
		{
			if (f1 == 0)
			{
				cout << setiosflags(ios::fixed) << setprecision(2) << i << " ";
				answer++;
			}
		}
		else if (f1 * f2 < 0)
		{
			double start = i, end = i + 1;
			double middle;
			while (start + 0.001 < end)
			{
				middle = (start + end) / 2;
				if (f(middle) == 0)
				{
					cout << setiosflags(ios::fixed) << setprecision(2) << middle << " ";
					answer++;
					break;
				}
				else if (f(middle) * f(start) < 0)
					end = middle;
				else
					start = middle;
			}
			if (start + 0.001 >= end)
			{
				cout << setiosflags(ios::fixed) << setprecision(2) << start << " ";
				answer++;
			}
		}
		if (answer == 3)
			return 0;
	}
	cout << "100.00";
	return 0;
}
double f(double x)
{
	return a * pow(x, 3) + b * pow(x, 2) + c * x + d;
}