#include <iostream>
#include <string>
using namespace std;
int main()
{
	string n;
	cin >> n;
	if (int(n[n.size() - 1]) % 2)
		cout << "ji" << endl;
	else
		cout << "ou" << endl;
	return 0;
}