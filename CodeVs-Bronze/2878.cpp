#include <iostream>
#include <string>
using namespace std;
int main()
{
	string a, b; cin >> a >> b;
	if (a[a.length() - 1] == '0' || a[a.length() - 1] == '5')
	{
		cout << "Yes" << endl;
		return 0;
	}
	if (b[b.length() - 1] == '0' || b[b.length() - 1] == '5')
	{
		cout << "Yes" << endl;
		return 0;
	}
	cout << "No" << endl;
	return 0;
}