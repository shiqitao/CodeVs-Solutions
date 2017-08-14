#include <iostream>
#include <unordered_set>  
using namespace std;
int n, k;
unordered_set<int> prime;
int maxPrime = 1;
int choose(const int data[], int sum, const int num, const int now);
bool ifPrime(const int n);
int main()
{
	cin >> n >> k;
	int *data = new int[n];
	for (int i = 0; i < n; i++)
		cin >> data[i];

	delete[] data;
	return 0;
}
int choose(const int data[], int sum, const int num, const int now)
{
	if (num == k) return prime(sum);
	if (n - now + num == k)
	{
		for (int i = now; i < n; i++)
			sum += data[i];
		return prime(sum);
	}
	return choose(data, sum + data[now], num + 1, now + 1) + choose(data, sum, num, now + 1);
}
bool ifPrime(const int n)
{
	if (n > maxPrime)
	{
		for (int i = maxPrime + 1; i <= n; i++)
		{
			unordered_set<int>::iterator iter = prime.begin();
			bool state = true;
			for (; iter != prime.end(); iter++)
			{
				if (i % *iter == 0)
					state = false;
			}
			if (state)
			{
				prime.insert(i);
				maxPrime = i;
			}
		}
		if (n == maxPrime) return true;
	}
	else if (prime.find(n) == prime.end()) return false;
	return true;
}