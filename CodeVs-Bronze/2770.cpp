#include <iostream>
using namespace std;
int main()
{
	int N, K;
	cin >> N >> K;
	int temp = N / K - K / 2 + 1 - K % 2;
	for (int i = 0; i < K; i++)
		cout << temp + i << " ";
	return 0;
}