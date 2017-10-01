#include <iostream>
using namespace std;
int main()
{
	unsigned long long data1 = 0, data2 = 1, data3 = 0, data4;
	int n; cin >> n;
	for (int i = 4; i <= n; i++)
	{
		if (i % 4 == 0)
			data4 = data1 + data2 + data3 + 1;
		else if (i % 4 == 1)
			data1 = data2 + data3 + data4 + 1;
		else if (i % 4 == 2)
			data2 = data3 + data4 + data1 + 1;
		else
			data3 = data4 + data1 + data2 + 1;
	}
	if (n % 4 == 0)
		cout << data4 << endl;
	else if (n % 4 == 1)
		cout << data1 << endl;
	else if (n % 4 == 2)
		cout << data2 << endl;
	else
		cout << data3 << endl;
	return 0;
}