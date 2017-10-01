#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	int x, y; cin >> x >> y;
	int temp = y / x;
	int sum = 0;
	int point = 2;
	while (temp != 1)
	{
		bool state = true;
		while (temp % point == 0)
		{
			temp /= point;
			sum += state;
			state = false;
		}
		point++;
	}
	cout << pow(2, sum) << endl;
	return 0;
}