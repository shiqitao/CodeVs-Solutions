#include <iostream>
using namespace std;
int main()
{
	int n; cin >> n;
	int *data = new int[n];
	for (int i = 0; i < n; i++)
		cin >> data[i];
	for (int i = 0; i < n; i++)
		cout << 10 - data[i] % 10 << " ";
	cout << endl;
	return 0;
}