#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	double temp;
	cin >> temp;
	cout << setiosflags(ios::fixed) << setprecision(2) << temp << endl;
	return 0;
}