#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main()
{
	int R; cin >> R;
	double v = sqrt(7.9 * 7.9 * 6400 / (R + 6400));
	cout << setiosflags(ios::fixed) << setprecision(2) << v << endl;
	return 0;
}