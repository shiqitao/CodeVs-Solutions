#include <iostream>
using namespace std;
struct Station
{
	int oil;
	int cost;
	int increase;
	Station *next;
};
int main()
{
	int n; cin >> n;
	Station *station = new Station[n];
	for (int i = 0; i < n; i++)
	{
		cin >> station[i].oil;
		station[i].next = &station[(i + 1) % n];
	}
	for (int i = 0; i < n; i++)
	{
		cin >> station[i].cost;
		station[i].increase = station[i].oil - station[i].cost;
	}
	int sum;
	Station *tempStation;
	bool ifResult = false;
	for (int i = 0; i < n; i++)
	{
		tempStation = &station[i];
		sum = 0;
		int j;
		for (j = 0; j < n; j++)
		{
			sum += tempStation->increase;
			if (sum < 0)
				break;
			tempStation = tempStation->next;
		}
		if (j == n)
		{
			cout << i + 1 << " ";
			ifResult = true;
		}
	}
	if (!ifResult)
		cout << "No Result!" << endl;
	delete[] station;
	return 0;
}