#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAX(x,y) x>y?x:y
#define MIN(x,y) x<y?x:y
string largePlus(const string num1, const string num2);
string largeMul(const string num1, const int num2, const int offset = 0);
string largeMultiple(const string num1, const string num2);
int main()
{
	string num1, num2; cin >> num1 >> num2;
	reverse(num1.begin(), num1.end());
	reverse(num2.begin(), num2.end());
	if (num2.size() > num1.size())
	{
		string temp = num2;
		num2 = num1;
		num1 = temp;
	}
	string result = largeMultiple(num1, num2);
	for (int i = result.size() - 1; i >= 0; i--)
		cout << result[i];
	cout << endl;
	return 0;
}
string largePlus(const string num1, const string num2)
{
	int bitsMAX = MAX(num1.size(), num2.size());
	int bitsMIN = MIN(num1.size(), num2.size());
	int carry = 0;
	string result = "";
	for (int i = 0; i < bitsMIN; i++)
	{
		result += num1[i] + num2[i] + carry - '0';
		if (result[i] > '9')
		{
			result[i] -= 10;
			carry = 1;
		}
		else carry = 0;
	}
	for (int i = bitsMIN; i < bitsMAX; i++)
	{
		if (num1.size() < num2.size()) result += num2[i] + carry;
		else result += num1[i] + carry;
		if (result[i] > '9')
		{
			result[i] -= 10;
			carry = 1;
		}
		else carry = 0;
	}
	if (carry == 1) result += '1';
	return result;
}
string largeMul(const string num1, const int num2, const int offset)
{
	string result = "";
	if (num2 == 0)
	{
		result = "0";
		return result;
	}
	int bits = num1.size();
	int carry = 0;
	int temp;
	for (int i = 0; i < offset; i++)
		result += '0';
	for (int i = 0; i < bits; i++)
	{
		temp = (num1[i] - '0')*num2 + carry;
		result += (temp % 10) + '0';
		carry = temp / 10;
	}
	if (carry != 0)
		result += carry + '0';
	return result;
}
string largeMultiple(const string num1, const string num2)
{
	int bits = num2.size();
	string result = "0";
	string temp;
	for (int i = 0; i < bits; i++)
	{
		temp = largeMul(num1, num2[i] - '0', i);
		result = largePlus(result, temp);
	}
	return result;
}