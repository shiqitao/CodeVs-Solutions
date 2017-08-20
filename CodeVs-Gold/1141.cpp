#include <iostream>
using namespace std;
int main()
{
	int k, N; cin >> k >> N;
	long long num = 0, count = 1;
	while (N != 0)
	{
		num += (N % 2)*count;
		count *= k;
		N /= 2;
	}
	cout << num << endl;
	return 0;
}