#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
struct Island
{
	double x;
	double y;
	double circle1;
	double circle2;
};
bool cmp(Island island1, Island island2);
int main()
{
	int n, d; cin >> n >> d;
	int caseNum = 0;
	while (n != 0)
	{
		caseNum++;
		Island *island = new Island[n];
		bool ifSolution = true;
		for (int i = 0; i < n; i++)
		{
			cin >> island[i].x >> island[i].y;
			if (d*d - island[i].y*island[i].y < 0 || d < 0)
			{
				for (int j = i + 1; j < n; j++)
					cin >> island[j].x >> island[j].y;
				ifSolution = false;
				break;
			}
			island[i].circle1 = island[i].x - sqrt(d*d - island[i].y*island[i].y);
			island[i].circle2 = island[i].x + sqrt(d*d - island[i].y*island[i].y);
		}
		if (ifSolution)
		{
			sort(island, island + n, cmp);
			int islandNum = 0;
			double circle = island[0].circle1 - 1;
			for (int i = 0; i < n; i++)
			{
				if (circle < island[i].circle1)
				{
					islandNum++;
					circle = island[i].circle2;
				}
			}
			cout << "Case " << caseNum << ": " << islandNum << endl;
		}
		else cout << "Case " << caseNum << ": -1" << endl;
		delete[] island;
		cin >> n >> d;
	}
	return 0;
}
bool cmp(Island island1, Island island2)
{
	return island1.circle2 < island2.circle2;
}