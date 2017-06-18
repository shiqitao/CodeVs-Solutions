#include <iostream>
#include <cmath>
using namespace std;
struct Data
{
	int m;
	unsigned short *kind;
};
int main()
{
	int n; cin >> n;
	Data *data = new Data[n];
	for (int i = 0; i < n; i++)
	{
		cin >> data[i].m;
		data[i].kind = new unsigned short[data[i].m];
		for (int j = 0; j < data[i].m; j++)
			cin >> data[i].kind[j];
	}
	int num[50];
	for (int k = 0; k < n; k++)
	{
		memset(num, 0, sizeof(int)* 50);
		for (int i = 0; i < data[k].m; i++)
			num[data[k].kind[i]]++;
		int temp = 0;
		int minIndex;
		for (int i = 0; i < data[k].m; i++)
		{
			temp += num[i];
			if (temp >= (data[k].m + 1) / 2)
			{
				minIndex = i;
				break;
			}
		}
		long long min = 0;
		for (int i = 0; i < minIndex; i++)
			min += (minIndex - i) * num[i];
		for (int i = minIndex + 1; i < 50; i++)
			min += (i - minIndex) * num[i];
		cout << minIndex << " " << min << endl;
	}
	for (int i = 0; i < n; i++)
		delete[] data[i].kind;
	delete[] data;
	return 0;
}