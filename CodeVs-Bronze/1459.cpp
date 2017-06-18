#include <iostream>
using namespace std;
int GCD(int num1, int num2);
int LCM(int num1, int num2);
int main()
{
	int n; cin >> n;
	int *data = new int[n];
	for (int i = 0; i < n; i++)
		cin >> data[i];
	int lcm = data[0];
	for (int i = 1; i < n; i++)
		lcm = LCM(lcm, data[i]);
	cout << lcm << endl;
	return 0;
}
int GCD(int num1, int num2)
{
	if (num1 < num2)
	{
		int temp = num1;
		num1 = num2;
		num2 = temp;
	}
	int c = num1 % num2;
	while (c != 0)
	{
		num1 = num2;
		num2 = c;
		c = num1 % num2;
	}
	return num2;
}
int LCM(int num1, int num2)
{
	int gcd = GCD(num1, num2);
	return num1 * num2 / gcd;
}