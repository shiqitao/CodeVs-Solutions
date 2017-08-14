#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int n; cin >> n;
	int *data = new int[n];
	for (int i = 0; i < n; i++)
		cin >> data[i];
	sort(data, data + n);
	int maxNum = 1;
	int diff, temp;
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			diff = data[j] - data[i];
			temp = 2;
			for (int k = j + 1; k < n; k++)
			{
				if (data[k] - data[i] == temp*diff)
					temp++;
			}
			maxNum = max(temp, maxNum);
		}
	}
	cout << maxNum << endl;
	delete[] data;
	return 0;
}