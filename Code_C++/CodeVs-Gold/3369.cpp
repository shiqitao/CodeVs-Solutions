#include <iostream>
#include <cstring>
using namespace std;
#define MAX(x,y) ((x)>(y)?(x):(y))
#define MIN(x,y) ((x)<(y)?(x):(y))
#define JUDGE(x) ((x)==1?1:-1)
int main()
{
	int N, M; cin >> N >> M;
	int *worship = new int[N];
	int *data = new int[N*N];
	cin >> worship[0];
	data[0] = worship[0] == 1 ? 1 : -1;
	for (int i = 1; i < N; i++)
	{
		cin >> worship[i];
		data[i] = data[i - 1] + JUDGE(worship[i]);
	}
	for (int i = 1; i < N; i++)
	{
		for (int j = i; j < N; j++)
			data[i*N + j] = data[(i - 1)*N + j] - JUDGE(worship[i - 1]);
	}
	int *DP = new int[N + 1];
	memset(DP, 127, sizeof(int)*(N + 1));
	DP[0] = 0;
	for (int i = 1; i < N + 1; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (data[j*N + i - 1] <= M && data[j*N + i - 1] >= -M || data[j*N + i - 1] == i - j || data[j*N + i - 1] == j - i)
				DP[i] = MIN(DP[i], DP[j] + 1);
		}
	}
	cout << DP[N] << endl;
	delete[] worship;
	delete[] data;
	delete[] DP;
	return 0;
}