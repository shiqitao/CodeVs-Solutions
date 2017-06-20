#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	int n; cin >> n;
	int *temp1 = new int[n];
	int *temp2 = new int[n];
	for (int i = 0; i < n; i++)
		cin >> temp1[i];
	for (int i = 0; i < n; i++)
		cin >> temp2[i];
	unsigned long long sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += pow((unsigned long long)temp1[i], (unsigned long long)temp2[i]);
	}
	cout << sum << endl;
	delete[] temp1;
	delete[] temp2;
	return 0;
}