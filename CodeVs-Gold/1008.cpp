#include <iostream>
#include <cmath>
using namespace std;
int n, k;
int choose(const int data[], int sum, const int num, const int now);
bool ifPrime(const int n);
int main()
{
	cin >> n >> k;
	int *data = new int[n];
	for (int i = 0; i < n; i++)
		cin >> data[i];
	cout << choose(data, 0, 0, 0) << endl;
	delete[] data;
	return 0;
}
int choose(const int data[], int sum, const int num, const int now)
{
	if (num == k) return ifPrime(sum);
	if (n - now + num == k)
	{
		for (int i = now; i < n; i++)
			sum += data[i];
		return ifPrime(sum);
	}
	return choose(data, sum + data[now], num + 1, now + 1) + choose(data, sum, num, now + 1);
}
bool ifPrime(const int n)
{
	if (n % 2 == 0) return false;
	else
	{
		double temp = sqrt(n);
		for (int i = 3; i <= temp; i += 2)
		{
			if (n % i == 0) return false;
		}
	}
	return true;
}