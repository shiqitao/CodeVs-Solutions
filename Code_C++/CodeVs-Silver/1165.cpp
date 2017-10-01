#include <iostream>
#include <string>
using namespace std;
int main()
{
	int p1, p2, p3;
	cin >> p1 >> p2 >> p3;
	string str; cin >> str;
	cout << str[0];
	for (int i = 1; i < str.length() - 1; i++)
	{
		if (str[i] == '-' && 'a' <= str[i - 1] && str[i - 1] < str[i + 1] && str[i + 1] <= 'z')
		{
			if (p1 == 1)
			{
				if (p3 == 1)
				{
					for (char j = str[i - 1] + 1; j < str[i + 1]; j++)
					{
						for (int k = 0; k < p2; k++)
							cout << j;
					}
				}
				else
				{
					for (char j = str[i + 1] - 1; j > str[i - 1]; j--)
					{
						for (int k = 0; k < p2; k++)
							cout << j;
					}
				}
			}
			else if (p1 == 2)
			{
				if (p3 == 1)
				{
					for (char j = str[i - 1] - 31; j < str[i + 1] - 32; j++)
					{
						for (int k = 0; k < p2; k++)
							cout << j;
					}
				}
				else
				{
					for (char j = str[i + 1] - 33; j > str[i - 1] - 32; j--)
					{
						for (int k = 0; k < p2; k++)
							cout << j;
					}
				}
			}
			else
			{
				for (char j = str[i - 1] + 1; j < str[i + 1]; j++)
				{
					for (int k = 0; k < p2; k++)
						cout << '*';
				}
			}
		}
		else if (str[i] == '-' && '0' <= str[i - 1] && str[i - 1] < str[i + 1] && str[i + 1] <= '9')
		{
			if (p1 != 3)
			{
				if (p3 == 1)
				{
					for (char j = str[i - 1] + 1; j < str[i + 1]; j++)
					{
						for (int k = 0; k < p2; k++)
							cout << j;
					}
				}
				else
				{
					for (char j = str[i + 1] - 1; j > str[i - 1]; j--)
					{
						for (int k = 0; k < p2; k++)
							cout << j;
					}
				}
			}
			else
			{
				for (char j = str[i - 1] + 1; j < str[i + 1]; j++)
				{
					for (int k = 0; k < p2; k++)
						cout << '*';
				}
			}
		}
		else cout << str[i];
	}
	cout << str[str.length() - 1];
	return 0;
}