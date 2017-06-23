#include <iostream>
using namespace std;
int main()
{
	int n; cin >> n;
	int now = 0; int sumTime = 0;
	int temp;
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		sumTime += 5;
		sumTime += (temp - now)>0 ? 6 * (temp - now) : 4 * (now - temp);
		now = temp;
	}
	cout << sumTime << endl;
	return 0;
}