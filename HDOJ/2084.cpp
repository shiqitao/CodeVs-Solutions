#include <iostream>
using namespace std;
#define MAX(x,y) (x>y?x:y) 
int main()
{
	int C; cin >> C;
	int *result = new int[C];
	for (int i = 0; i < C; i++)
	{
		int N; cin >> N;
		int *data = new int[N*N];
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < i + 1; j++)
				cin >> data[i*N + j];
		}
		for (int i = N - 2; i >= 0; i--)
		{
			for (int j = 0; j < i + 1; j++)
				data[i*N + j] += MAX(data[(i + 1)*N + j], data[(i + 1)*N + j + 1]);
		}
		result[i] = data[0];
		delete[] data;
	}
	for (int i = 0; i < C; i++)
		cout << result[i] << endl;
	delete[] result;
	return 0;
}