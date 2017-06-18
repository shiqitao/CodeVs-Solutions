#include <iostream>
#include <cmath>
using namespace std;
bool partition(int *n, int *start);
int main()
{
	int n; cin >> n;
	cout << n << "=";
	int temp = sqrt(n);
	int start = -1;
	for (int i = 2; i <= temp; i++)
	{
		if (n % i == 0)
		{
			start = i;
			n = n / i;
			cout << i;
			break;
		}
	}
	if (start == -1)
		cout << temp << endl;
	else
		while (partition(&n, &start));
	return 0;
}
bool partition(int *n, int *start)
{
	int temp = sqrt(*n);
	for (int i = *start; i <= temp; i++)
	{
		if (*n % i == 0)
		{
			cout << "*" << i;
			*start = i;
			*n /= i;
			return true;
		}
	}
	cout << "*" << *n << endl;
	return false;
}