#include <iostream>
#include <limits.h>
using namespace std;
int main()
{
	int n; cin >> n;
	int data1, data2;
	int minData1, minData2;
	cin >> data1;
	minData1 = data1;
	int min = INT_MAX;
	int temp;
	for (int i = 1; i < n; i++)
	{
		cin >> data2;
		temp = data2 - data1 >= 0 ? data2 - data1 : data1 - data2;
		if (temp < min)
		{
			minData1 = data1;
			minData2 = data2;
			min = temp;
		}
		data1 = data2;
	}
	cout << minData1 << " " << minData2 << endl;
	return 0;
}