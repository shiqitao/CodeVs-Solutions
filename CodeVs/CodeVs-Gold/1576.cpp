#include <iostream>
#include <cstring>
using namespace std;
#define MAX(x,y) x>y?x:y
int main()
{
	int n; cin >> n;
	int *data = new int[n];
	for (int i = 0; i < n; i++)
		cin >> data[i];
	int *DP = new int[n];
	memset(DP, 0, sizeof(int)*n);
	int max = 0;
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (data[i] > data[j] && DP[i] <= DP[j])
				DP[i] = DP[j] + 1;
		}
		max = MAX(max, DP[i]);
	}
	cout << max + 1 << endl;
	delete[] data;
	delete[] DP;
	return 0;
}