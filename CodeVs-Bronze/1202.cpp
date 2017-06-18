#include <iostream>
using namespace std;
int main()
{
	unsigned short n;
	int sum = 0;
	int temp;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		sum += temp;
	}
	cout << sum << endl;
	return 0;
}