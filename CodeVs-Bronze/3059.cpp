#include <iostream>
using namespace std;
int main()
{
	int n; cin >> n;
	int sum = 0;
	int temp;
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		if (temp <= 10)
			sum += 50;
		else if (temp <= 100)
			sum += 180;
		else if (temp <= 300)
			sum += 300;
		else if (temp <= 1000)
			sum += 1000;
		else if (temp <= 3000)
			sum += 2000;
		else
		{
			cout << "Can't transport!" << endl;
			return 0;
		}
	}
	cout << sum << endl;
	return 0;
}