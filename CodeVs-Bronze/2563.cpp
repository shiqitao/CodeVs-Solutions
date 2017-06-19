#include <iostream>
#include <string>
using namespace std;
int main()
{
	int n; cin >> n;
	string num; cin >> num;
	int power = 1;
	int sum = 0;
	for (int i = n - 1; i >= 0; i--)
	{
		sum += (num[i] - 48) * power;
		power *= 2;
	}
	cout << sum << endl;
	return 0;
}