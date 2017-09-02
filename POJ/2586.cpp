#include <iostream>
using namespace std;
int main()
{
	int s, d;
	while (cin >> s >> d)
	{
		int numS;
		double ratio = (double)d / s;
		if (ratio > 4.0 / 1) numS = 10;
		else if (ratio > 3.0 / 2) numS = 8;
		else if (ratio > 2.0 / 3) numS = 6;
		else if (ratio > 1.0 / 4) numS = 3;
		else numS = 0;
		int result = numS*s - (12 - numS)*d;
		if (result >= 0) cout << result << endl;
		else cout << "Deficit" << endl;
	}
	return 0;
}