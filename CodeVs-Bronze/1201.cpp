#include <iostream>
using namespace std;
int main()
{
	unsigned short n;
	int min = INT_MAX;
	int max = INT_MIN;
	int temp;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		if (temp < min) min = temp;
		if (temp > max) max = temp;
	}
	cout << min << " " << max << endl;
	return 0;
}