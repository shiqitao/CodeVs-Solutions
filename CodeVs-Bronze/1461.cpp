#include <iostream>
#include <string>
using namespace std;
int main()
{
	int data[26] = { 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 4, 1, 2, 3, 1, 2, 3, 4 };
	string str; getline(cin, str);
	int sum = 0;
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] >= 97)
			sum += data[str[i] - 97];
		else
			sum++;
	}
	cout << sum << endl;
	return 0;
}