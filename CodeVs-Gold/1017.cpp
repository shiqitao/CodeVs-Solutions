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
	int *data = new int[N*K];
	memset(data, 0, sizeof(int)*N*K);
	for (int i = 0; i < N; i++)
		data[i*K] = number(num, 0, i + 1);
	for (int i = 1; i < N; i++)
	{
		for (int j = 1; j < K; j++)
		{
			for (int k = 0; k < i; k++)
			{
				if (data[k*K + j - 1] != 0)
					data[i*K + j] = MAX(data[i*K + j], data[k*K + j - 1] * number(num, k + 1, i + 1));
			}
		}
	}
	cout << data[N*K - 1] << endl;
	delete[] num;
	delete[] data;
	return 0;
}
int number(int num[], int start, int end)
{
	int sum = 0;
	for (int i = start; i < end; i++)
		sum = sum * 10 + num[i];
	return sum;
}