#include <iostream>
using namespace std;
int main()
{
	int a, b;
	cin >> a >> b;
	int *data = new int[a];
	for (int i = 0; i < a; i++)
		cin >> data[i];
	int sum = 0;
	for (int i = 0; i < a; i++)
	{
		for (int j = i + 1; j < a; j++)
		{
			if (data[i] * (i + 1) == data[j] * (j + 1))
			{
				int index = (i + j) / 2;
				if (b)
				{
					for (int k = index; k < a; k++)
						sum += data[k];
				}
				else
				{
					for (int k = 0; k <= index; k++)
						sum += data[k];
				}
				cout << index + 1 << " " << sum << endl;
				return 0;
			}
		}
	}
}