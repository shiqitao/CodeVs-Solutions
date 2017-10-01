#include <iostream>
#include <cstring>
using namespace std;
#define MAX(x,y) (x>y?x:y)
int number(int num[], int start, int end);
int main()
{
	int N, K; cin >> N >> K; K++;
	int *num = new int[N];
	char ch;
	for (int i = 0; i < N; i++)
	{
		cin >> ch;
		num[i] = ch - '0';
	}
	int *DP = new int[N*K];
	memset(DP, 0, sizeof(int)*N*K);
	for (int i = 0; i < N; i++)
		DP[i*K] = number(num, 0, i + 1);
	for (int i = 1; i < N; i++)
	{
		for (int j = 1; j < K; j++)
		{
			for (int k = 0; k < i; k++)
			{
				if (DP[k*K + j - 1] != 0)
					DP[i*K + j] = MAX(DP[i*K + j], DP[k*K + j - 1] * number(num, k + 1, i + 1));
			}
		}
	}
	cout << DP[N*K - 1] << endl;
	delete[] num;
	delete[] DP;
	return 0;
}
int number(int num[], int start, int end)
{
	int sum = 0;
	for (int i = start; i < end; i++)
		sum = sum * 10 + num[i];
	return sum;
}