#include <iostream>
#include <limits.h>
using namespace std;
int main()
{
	int n; cin >> n;
	int max1 = INT_MIN, max2 = INT_MIN;
	int temp;
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		if (temp > max1)
		{
			max2 = max1;
			max1 = temp;
		}
		else if (temp > max2)
			max2 = temp;
	}
	cout << max2 << endl;
	return 0;
}