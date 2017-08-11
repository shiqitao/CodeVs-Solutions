#include <iostream>
#include <string>
using namespace std;
int main()
{
	string str;
	cin >> str;
	int n = str[0] - 48;
	for (int i = 2; i < 5; i++)
		n += (str[i] - 48)*i;
	for (int i = 6; i < 11; i++)
		n += (str[i] - 48)*(i - 1);
	n %= 11;
	char X = n < 10 ? n + 48 : 'X';
	if (X == str[12]) cout << "Right" << endl;
	else
	{
		str[12] = X;
		cout << str << endl;
	}
	return 0;
}