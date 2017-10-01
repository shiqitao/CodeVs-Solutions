#include <iostream>
#include <cstring>
using namespace std;
struct Data
{
	int n;
	int q;
	int result;
};
void multiply(int A[], int B[], int result[], int mod);
void power(int A[], int n, int result[], int mod);
int main()
{
	int T; cin >> T;
	Data *data = new Data[T];
	int A[4] = { 1, 1, 1, 0 };
	for (int i = 0; i < T; i++)
	{
		cin >> data[i].n >> data[i].q;
		int result[4];
		if (data[i].n == 0)
		{
			data[i].result = 1 % data[i].q;
			continue;
		}
		power(A, data[i].n, result, data[i].q);
		data[i].result = result[0] % data[i].q;
	}
	for (int i = 0; i < T; i++)
		cout << data[i].result << endl;
	delete[] data;
	return 0;
}
void multiply(int A[], int B[], int result[], int mod)
{
	result[0] = (A[0] * B[0] + A[1] * B[2]) % mod;
	result[1] = (A[0] * B[1] + A[1] * B[3]) % mod;
	result[2] = (A[2] * B[0] + A[3] * B[2]) % mod;
	result[3] = (A[2] * B[1] + A[3] * B[3]) % mod;
}
void power(int A[], int n, int result[], int mod)
{
	if (n == 1)
	{
		memcpy(result, A, sizeof(int)* 4);
		return;
	}
	int temp[4];
	power(A, n >> 1, result, mod);
	multiply(result, result, temp, mod);
	if (n % 2) multiply(temp, A, result, mod);
	else memcpy(result, temp, sizeof(int)* 4);
}