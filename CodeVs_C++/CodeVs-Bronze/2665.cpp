#include <iostream>
using namespace std;
int main()
{
	int a, b, c;
	cin >> a >> b >> c;
	if (a + b <= c)
	{
		cout << "no" << endl;
		return 0;
	}
	else if (a + c <= b)
	{
		cout << "no" << endl;
		return 0;
	}
	else if (b + c <= a)
	{
		cout << "no" << endl;
		return 0;
	}
	cout << "yes" << endl;
	return 0;
}