#include <iostream>
using namespace std;
int main()
{
	int n; cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < n - i; j++)
			cout << " ";
		cout << "/";
		for (int j = 0; j < i - 1; j++)
			cout << "__";
		cout << "\\";
		for (int j = 0; j < n - i; j++)
			cout << " ";
		cout << endl;
	}
	return 0;
}