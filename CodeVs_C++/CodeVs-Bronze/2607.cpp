#include <iostream>
using namespace std;
int main()
{
	char type; cin >> type;
	int n; cin >> n;
	if (type == 'Z')
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
				cout << "*";
			cout << endl;
		}
	}
	else
	{
		for (int i = 0; i < n - 1; i++)
		{
			for (int j = 0; j < n - 1 - i; j++)
				cout << " ";
			for (int j = 0; j < 2 * i + 1; j++)
				cout << "*";
			cout << endl;
		}
		for (int j = 0; j < 2 * n - 1; j++)
			cout << "*";
		cout << endl;
		for (int i = n - 2; i >= 0; i--)
		{
			for (int j = 0; j < n - 1 - i; j++)
				cout << " ";
			for (int j = 0; j < 2 * i + 1; j++)
				cout << "*";
			cout << endl;
		}
	}
	return 0;
}