#include <iostream>
#include <cmath>
using namespace std;
#define MIN(x,y) ((x)<(y)?(x):(y))
int main()
{
	int n; cin >> n; n++;
	int *distance = new int[n*n];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cin >> distance[i*n + j];
	}
	for (int k = 0; k < n; k++)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
				distance[i*n + j] = MIN(distance[i*n + j], distance[i*n + k] + distance[k*n + j]);
		}
	}
	int state = pow(2, n);
	int *DP = new int[state*n];


	delete[] distance;
	return 0;
}