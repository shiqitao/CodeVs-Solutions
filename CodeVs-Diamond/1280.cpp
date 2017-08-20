#include <iostream>
using namespace std;
int main()
{
	int n; cin >> n;
	int *result = new int[n];
	long long int temp;
	for (int i = 0; i < n; i++)
	{
		long long int numBit = 1; long long int count = 9;
		cin >> temp;
		while (temp > count*numBit)
		{
			temp -= count*numBit;
			numBit++;
			count *= 10;
		}
		long long int num = (temp - 1) / numBit + 1;
		temp = (temp - 1) % numBit;
		num = count / 9 + num - 1;
		temp = numBit - temp - 1;
		for (int j = temp; j > 0; j--)
			num /= 10;
		result[i] = num % 10;
	}
	for (int i = 0; i < n; i++)
		cout << result[i] << endl;
	delete[] result;
	return 0;
}