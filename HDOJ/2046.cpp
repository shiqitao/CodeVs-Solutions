#include <iostream>
using namespace std;
int main()
{
	long long data[51] = { 1, 1 };
	for (int i = 2; i < 51; i++)
		data[i] = data[i - 1] + data[i - 2];
	int n;
	while (cin >> n)
		cout << data[n] << endl;
	return 0;
}