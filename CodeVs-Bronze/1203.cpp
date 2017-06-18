#include <iostream>
using namespace std;
int main()
{
	double a, b;
	cin >> a >> b;
	if (a - b <= 1e-8 && a - b >= -1e-8)
		cout << "yes" << endl;
	else
		cout << "no" << endl;
	return 0;
}