#include <iostream>
using namespace std;
#define MAX(x,y) ((x)>(y)?(x):(y))
int main()
{
	int n; cin >> n;
	int *DP = new int[n*n];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= i; j++)
			cin >> DP[i*n + j];
	}
	for (int i = n - 2; i >= 0; i--)
	{
		for (int j = 0; j <= i; j++)
			DP[i*n + j] += MAX(DP[(i + 1)*n + j], DP[(i + 1)*n + j + 1]);
	}
	cout << DP[0] << endl;
	delete[] DP;
	return 0;
}