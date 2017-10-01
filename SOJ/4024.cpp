/**********
ID:4024
Author:Qitao Shi
Date:2017-09-25
**********/
#include <iostream>
using namespace std;
int main()
{
	int a, b;
	cin >> a >> b;
	if (b > 0)
	{
		cout << a << "+" << b << "=" << a + b << endl;
		cout << a << "*" << b << "=" << a*b << endl;
		cout << a << "/" << b << "=" << a / b << endl;
		cout << a << "%" << b << "=" << a%b << endl;
	}
	else if (b < 0)
	{
		cout << a << "+(" << b << ")=" << a + b << endl;
		cout << a << "*(" << b << ")=" << a*b << endl;
		cout << a << "/(" << b << ")=" << a / b << endl;
		cout << a << "%(" << b << ")=" << a%b << endl;
	}
	else
	{
		cout << a << "+0=" << a << endl;
		cout << a << "*0=0" << endl;
		cout << a << "/0:Error!" << endl;
		cout << a << "%0:Error!" << endl;
	}
	return 0;
}