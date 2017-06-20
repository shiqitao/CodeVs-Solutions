#include <iostream>
using namespace std;
int main()
{
	int n; cin >> n;
	int min = 32768;
	int max = 0;
	int sum = 0;
	int temp;
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		sum += temp;
		if (max < temp)
			max = temp;
		if (min > temp)
			min = temp;
	}
	cout << max << endl << min << endl << int((double)sum / n + 0.5) << endl;
	return 0;
}