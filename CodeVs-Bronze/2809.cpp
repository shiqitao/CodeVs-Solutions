#include <iostream>
using namespace std;
int main()
{
	int n; cin >> n;
	int m = n;
	int start = n / 2 + 1;
	start = start % 2 ? start + 1 : start;
	int temp;
	for (int i = start; i <= n; i += 2)
	{
		temp = i / 2; m--;
		while (temp % 4 == 0)
		{
			temp = temp / 4;
			m--;
		}
	}
	cout << m << endl;
	return 0;
}