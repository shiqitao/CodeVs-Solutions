#include <iostream>
using namespace std;
unsigned int C(int n, int m);
int main()
{
	int n, m; cin >> n >> m;
	unsigned int sum = 0;
	int temp = m;
	bool state = false;
	while (temp > 0)
	{
		if (temp % 2 == 0 && !state)
		{
			sum += C(temp, temp / 2);
			state = true;
		}
		else if (!state) state = true;
		else if (temp % 2 == 0)
			sum += 2 * C(m, temp / 2);
		temp -= n;
	}
	if (temp == 0) sum += 2;
	cout << sum << endl;
	return 0;
}
unsigned int C(int n, int m)
{
	m = m > n - m ? n - m : m;
	unsigned int sum = 1;
	for (int i = 0; i < m; i++)
	{
		sum *= n - i;
		sum /= 1 + i;
	}
	return sum;
}