#include <iostream>
using namespace std;
int main()
{
	int n; cin >> n;
	int result; cin >> result;
	char ope;
	int temp;
	for (int i = 0; i < n; i++)
	{
		cin >> ope; cin >> temp;
		if (ope == '+')
			result += temp;
		else if (ope == '-')
			result -= temp;
		else if (ope == '*')
			result *= temp;
		else if (ope == '/')
		{
			if (temp == 0)
			{
				cout << "Error!" << endl;
				return 0;
			}
			result /= temp;
		}
		else if (ope == '%')
		{
			if (temp == 0)
			{
				cout << "Error!" << endl;
				return 0;
			}
			result %= temp;
		}
	}
	cout << result << endl;
	return 0;
}