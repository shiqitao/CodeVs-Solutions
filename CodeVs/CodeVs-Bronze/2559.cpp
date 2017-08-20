#include <iostream>
using namespace std;
int main()
{
	int moon, night;
	cin >> moon >> night;
	if (moon * 3 + night * 60 >= 480)
		cout << "YES" << endl;
	else
		cout << "No" << endl;
	return 0;
}