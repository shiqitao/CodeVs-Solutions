#include <iostream>
#include <limits.h>
using namespace std;
int main()
{
	int data;
	int max = INT_MIN;
	int temp1, temp2;
	for (int i = 1; i <= 7; i++)
	{
		cin >> temp1 >> temp2;
		if (max < temp1 + temp2)
		{
			data = i;
			max = temp1 + temp2;
		}
	}
	data = max > 8 ? data : 0;
	cout << data << endl;
	return 0;
}