#include <iostream>
using namespace std;
int iteration(int n);
int main()
{
	int n; cin >> n;
	cout << iteration(n) << endl;
	return 0;
}
int iteration(int n)
{
	return n == 0 ? 0 : (n + 1) / 2 + iteration(n / 4);
}