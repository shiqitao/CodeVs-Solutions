#include <iostream>
#include <string>
using namespace std;
bool cmp(string a, string b);
int main()
{
	int n; cin >> n;
	string *data = new string[n];
	for (int i = 0; i < n; i++)
		cin >> data[i];
	string temp;
	for (int i = 0; i < n; i++)
	{
		for (int j = n - 1; j > i; j--)
		{
			if (cmp(data[j], data[j - 1]))
			{
				temp = data[j];
				data[j] = data[j - 1];
				data[j - 1] = temp;
			}
		}
		cout << data[i] << endl;
	}
	return 0;
}
bool cmp(string a, string b)
{
	if (a.length() < b.length())
		return true;
	else if (a.length() > b.length())
		return false;
	else
	{
		for (int i = 0; i < a.length(); i++)
		{
			if (a[i] < b[i])
			{
				return true;
				break;
			}
			else if (a[i] > b[i])
			{
				return false;
				break;
			}
		}
		return false;
	}
}