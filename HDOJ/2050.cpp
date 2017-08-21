#include <iostream>
using namespace std;
int main()
{
	int C; cin >> C;
	int *result = new int[C];
	for (int i = 0; i < C; i++)
	{
		int n; cin >> n;
		if (n == 1) result[i] = 2;
		else
		{
			result[i] = 2;
			for (int j = 1; j < n; j++)
				result[i] += 4 * j + 1;
		}
	}
	for (int i = 0; i < C; i++)
		cout << result[i] << endl;
	delete[] result;
	return 0;
}