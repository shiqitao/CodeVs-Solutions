#include <iostream>
using namespace std;
int main()
{
	int K; cin >> K;
	long long result = 1;
	for (int i = 0; i < K; i++)
	{
		result *= 2 * K - i;
		result /= (i + 1);
	}
	result /= K + 1;
	cout << result << " " << K + 1 << endl;
	return 0;
}