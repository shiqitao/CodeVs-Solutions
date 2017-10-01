#include <iostream>
#include <string>
using namespace std;
int main()
{
	char x; cin >> x;
	int n; cin >> n;
	string data; cin >> data;
	if (x>='a' && x<='z')
	{
		cout << "I do not like lowercase letters!" << endl;
		return 0;
	}
	else if (x >= 'A' && x <= 'Z')
	{
		int sum = 0;
		for (int i = 0; i < n; i++)
		{
			if (data[i] == x)
				sum++;
		}
		cout << sum << endl;
		return 0;
	}
}