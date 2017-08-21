#include <iostream>
using namespace std;
int main()
{
	int N; cin >> N;
	long long *result = new long long[N];
	for (int i = 0; i < N; i++)
	{
		int M; cin >> M;
		if (M == 2) result[i] = 1;
		else if (M == 3) result[i] = 2;
		else
		{
			long long temp1 = 1;
			long long temp2 = 2;
			for (int j = 4; j <= M; j++)
			{
				result[i] = temp1 + temp2;
				temp1 = temp2;
				temp2 = result[i];
			}
		}
	}
	for (int i = 0; i < N; i++)
		cout << result[i] << endl;
	delete[] result;
	return 0;
}