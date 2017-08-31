#include <iostream>
#include <cstring>
using namespace std;
#define MAX(x,y) ((x)>(y)?(x):(y))
#define offset 1500
int *DP[offset * 2 + 1];
int main()
{
	int N; cin >> N;
	int *data = new int[N];
	for (int i = 0; i < N; i++)
		cin >> data[i];
	int result = 0;
	for (int i = 0; i < offset * 2 + 1; i++)
	{
		DP[i] = new int[N];
		memset(DP[i], 0, sizeof(int)*N);
	}
	for (int i = 1; i < N; i++)
	{
		for (int j = 0; j < i; j++)
		{
			DP[data[i] - data[j] + offset][i] = DP[data[i] - data[j] + offset][j] + 1;
			result = MAX(result, DP[data[i] - data[j] + offset][i]);
		}
	}
	cout << result + 1 << endl;
	delete[] data;
	return 0;
}