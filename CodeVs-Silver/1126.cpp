#include <iostream>
using namespace std;
int two(int n);
int main()
{
	int L, R; cin >> L >> R;
	int sum = 0;
	for (int i = L; i <= R; i++)
		sum += two(i);
	cout << sum << endl;
	return 0;
}
int two(int n)
{
	int sum = 0;
	while (n != 0)
	{
		if (n % 10 == 2)
			sum++;
		n /= 10;
	}
	return sum;
}