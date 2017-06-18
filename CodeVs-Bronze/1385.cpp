#include <iostream>
using namespace std;
bool timeUse[1000000];
int main()
{
	int n; cin >> n;
	int start, end, minTime = 1000000, maxTime = 0;
	memset(timeUse, false, sizeof(bool)* 1000000);
	for (int i = 0; i < n; i++)
	{
		cin >> start;
		cin >> end;
		if (start < minTime) minTime = start;
		if (end > maxTime) maxTime = end;
		memset(&timeUse[start], true, sizeof(bool)* (end - start));
	}
	int longTime[2] = { 0, 0 };
	int longTimeTemp[2] = { 0, 0 };
	bool state = timeUse[minTime - 1];
	bool thisState;
	for (int i = minTime; i < maxTime + 1; i++)
	{
		thisState = timeUse[i];
		if (thisState == state)
		{
			longTimeTemp[state]++;
			state = thisState;
		}
		else
		{
			if (longTimeTemp[0] > longTime[0]) longTime[0] = longTimeTemp[0];
			if (longTimeTemp[1] > longTime[1]) longTime[1] = longTimeTemp[1];
			longTimeTemp[0] = 0; longTimeTemp[1] = 0;
			longTimeTemp[thisState]++;
			state = thisState;
		}
	}
	cout << longTime[1] << " " << longTime[0] << endl;
	return 0;
}