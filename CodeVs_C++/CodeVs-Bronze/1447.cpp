#include <iostream>
using namespace std;
int main()
{
	int n, k;
	cin >> n >> k;
	int temp = n;
	int bit = 0;
	int number[31];
	while (temp != 0)
	{
		number[bit] = temp % 10;
		bit++;
		temp /= 10;
	}
	if (k > bit || -k > bit) cout << "Error" << endl;
	else if (k == bit || k == -bit || k == 0) cout << n << endl;
	else if (k > 0)
	{
		bool out = false;
		for (int i = 0; i < k - 1; i++)
		{
			if (!out)
			{
				if (number[bit - 1 - i])
					out = true;
				else
					continue;
			}
			cout << number[bit - 1 - i];
		}
		cout << number[bit - k] << endl;
	}
	else if (k < 0)
	{
		for (int i = 0; i < -k - 1; i++)
		{
			bool out = false;
			if (!out)
			{
				if (number[-k - 1 - i])
					out = true;
				else
					continue;
			}
			cout << number[-k - 1 - i];
		}
		cout << number[0] << endl;
	}
	return 0;
}