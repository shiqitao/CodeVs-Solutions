#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	unsigned short num;
	cin >> num;
	unsigned short unit;
	float grade;
	unsigned short unitSum = 0;
	float sum = 0;
	for (int i = 0; i < num; i++) {
		cin >> unit >> grade;
		unitSum += unit;
		sum += unit * grade;
	}
	cout << setiosflags(ios::fixed) << setprecision(2) << (float)sum / unitSum << endl;
	return 0;
}