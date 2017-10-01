#include <iostream>
using namespace std;
int main()
{
	unsigned short remain = 0;
	unsigned short budget = 0;
	unsigned short bank;
	unsigned short bankSum = 0;
	for (int i = 0; i < 12; i++)
	{
		remain += 300;
		cin >> budget;
		if (remain < budget)
		{
			cout << "-" << i + 1 << endl;
			return 0;
		}
		bank = (remain - budget) / 100;
		bankSum += bank;
		remain -= bank * 100 + budget;
	}
	cout << remain + bankSum * 100 + bankSum * 20 << endl;
	return 0;
}