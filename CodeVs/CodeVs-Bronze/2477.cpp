#include <iostream>
using namespace std;
int main()
{
	int n; cin >> n;
	switch (n % 5)
	{
	case 0:cout << "p" << endl; break;
	case 1:cout << "r" << endl; break;
	case 2:cout << "b" << endl; break;
	case 3:cout << "y" << endl; break;
	case 4:cout << "g" << endl; break;
	}
	return 0;
}