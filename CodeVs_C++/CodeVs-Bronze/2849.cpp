#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	int x; cin >> x;
	for (int i = 2; i < sqrt(x); i++)
	{
		if (x % i == 0)
		{
			cout << "composite" << endl;
			return 0;
		}
	}
	cout << "prime" << endl;
	return 0;
}