#include <iostream>
using namespace std;
int main()
{
	int n; cin >> n;
	int bit = 0;
	while (n != 0)
	{
		n /= 10;
		bit++;
	}
	cout << bit << endl;
	return 0;
}