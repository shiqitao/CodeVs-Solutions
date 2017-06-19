#include <iostream>
using namespace std;
int main()
{
	int n; cin >> n;
	int result = 0;
	int temp;
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		result ^= temp;
	}
	cout << result << endl;
	return 0;
}