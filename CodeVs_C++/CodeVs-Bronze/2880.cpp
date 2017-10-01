#include <iostream>
#include <limits.h>
using namespace std;
int main()
{
	int n; cin >> n;
	int *time = new int[n];
	int sum = 0;
	int max = INT_MIN;
	int min = INT_MAX;
	for (int i = 0; i < n - 1; i++)
	{
		cin >> time[i];
		sum += time[i];
		if (time[i] > max)
			max = time[i];
		if (time[i] < min)
			min = time[i];
	}
	double ave = (double)sum / (n - 1);
	int temp = 0;
	if (min >= ave * 0.9 && max <= ave * 1.1)
		temp++;
	cin >> time[n - 1];
	if (time[n - 1] <= min)
		temp++;
	if (temp == 0)
		cout << "Bad" << endl;
	else if (temp==1)
		cout << "Pass" << endl;
	else
		cout << "Good" << endl;
	delete[] time;
	return 0;
}