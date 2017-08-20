#include <iostream>
#include <string>
using namespace std;
int main()
{
	string str1, str2;
	cin >> str1 >> str2;
	int num1 = 1, num2 = 1;
	for (int i = 0; i < str1.length(); i++)
		num1 *= str1[i] - 64;
	for (int i = 0; i < str2.length(); i++)
		num2 *= str2[i] - 64;
	if (num1 % 47 == num2 % 47)
		cout << "GO" << endl;
	else
		cout << "STAY" << endl;
	return 0;
}