#include <iostream>
using namespace std;
int main()
{
	long long data[40] = { 1, 3 };
	for (int i = 2; i < 40; i++)
		data[i] = 2 * (data[i - 1] + data[i - 2]);
	int n;
	while (cin >> n)
		cout << data[n] << endl;
	return 0;
}