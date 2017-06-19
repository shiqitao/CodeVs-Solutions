#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
int main()
{
	int n; cin >> n;
	bool *num = new bool[n + 1];
	memset(num, true, sizeof(bool)* n + 1);
	int temp = sqrt(n);
	for (int i = 2; i <= temp; i++)
	{
		for (int j = 2; j <= n / i; j++)
			num[i * j] = false;
	}
	for (int i = 2; i <= n; i++)
	{
		if (num[i])
			cout << i << " ";
	}
	cout << endl;
	return 0;
}