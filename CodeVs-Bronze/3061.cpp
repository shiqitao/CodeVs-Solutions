#include <iostream>
using namespace std;
int main()
{
	int a, b; cin >> a >> b;
	char c; cin >> c;
	if (c == '+')
		cout << a + b << endl;
	else if (c == '-')
		cout << a - b << endl;
	else if (c == '*')
		cout << a * b << endl;
	else if (c == '/')
		cout << a / b << endl;
	return 0;
}