#include <iostream>
using namespace std;
int dfs(int n);
int main()
{
	int n; cin >> n;
	cout << dfs(n) << endl;
	return 0;
}
int dfs(int n)
{
	if (n == 1)
		return 1;
	else
	{
		int sum = 1;
		for (int i = 1; i <= n / 2; i++)
			sum += dfs(i);
		return sum;
	}
}