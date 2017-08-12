#include <iostream>
using namespace std;
int num(int n);
int data[10] = { 6, 2, 5, 5, 4, 5, 6, 3, 7, 6 };
int main()
{
	int n; cin >> n;
	int sum = 0;
	for (int i = 0; i < 1000; i++)
	{
		if (4 + num(i) * 2 + num(i * 2) == n) sum++;
		for (int j = i + 1; j < 1000; j++)
			if (4 + num(i) + num(j) + num(i + j) == n) sum += 2;
	}
	cout << sum << endl;
	return 0;
}
int num(int n)
{
	if (n == 0) return data[0];
	int sum = 0;
	while (n != 0)
	{
		sum += data[n % 10];
		n /= 10;
	}
	return sum;
}