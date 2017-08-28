#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
#define MAX(x,y) x>y?x:y
int main()
{
	int temp;
	vector<int> data;
	while (cin >> temp)
		data.push_back(temp);
	int *DP = new int[data.size()];
	memset(DP, 0, sizeof(int)*data.size());
	int max = 0;
	for (int i = 1; i < data.size(); i++)
	{
		for (int j = i - 1; j >= 0; j--)
		{
			if (data[i] <= data[j] && DP[i] <= DP[j])
				DP[i] = DP[j] + 1;
		}
		max = MAX(max, DP[i]);
	}
	cout << max + 1 << endl;
	delete[] DP;
	int *GREEDY = new int[data.size()];
	memset(GREEDY, 0, sizeof(int)*data.size());
	max = 0;
	for (int i = 1; i < data.size(); i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (data[i] > data[j] && GREEDY[i] <= GREEDY[j])
				GREEDY[i] = GREEDY[j] + 1;
		}
		max = MAX(max, GREEDY[i]);
	}
	cout << max + 1 << endl;
	delete[] GREEDY;
	return 0;
}