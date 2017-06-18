#include <iostream>
using namespace std;
int main()
{
	int n; cin >> n;
	int temp = n;
	for (int i = 2; i < n; i++)
		temp *= i;
	cout << temp << endl;
	return 0;
}