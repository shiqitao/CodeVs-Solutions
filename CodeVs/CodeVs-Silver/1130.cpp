#include <iostream>
using namespace std;
int main()
{
	bool sign;
	int n; cin >> n;
	if (n >= 0) sign = true;
	else
	{
		sign = false;
		n = -n;
	}
	int temp = 0;
	while (n != 0)
	{
		temp = temp * 10 + n % 10;
		n = n / 10;
	}
	if (!sign) temp = -temp;
	cout << temp << endl;
	return 0;
}