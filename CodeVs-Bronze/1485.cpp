#include <iostream>
#include <string>
#include <cstring>
using namespace std;
int main()
{
	string str;
	cin >> str;
	bool num[26];
	memset(num, 0, sizeof(bool)* 26);
	for (int i = 0; i < str.length(); i++)
		num[str[i] - 97] = !num[str[i] - 97];
	int sum = 0;
	for (int i = 0; i < 26; i++)
		sum += num[i];
	cout << sum << endl;
	return 0;
}