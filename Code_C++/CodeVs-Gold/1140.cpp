#include <iostream>
using namespace std;
int num;
char first, last;
bool JAM(char ch[]);
int main()
{
	int s, t; cin >> s >> t >> num;
	first = s + 'a' - 1;
	last = t + 'a' - 1;
	char *ch = new char[num];
	for (int i = 0; i < num; i++)
		cin >> ch[i];
	for (int i = 0; i < 5; i++)
	{
		if (JAM(ch))
		{
			for (int j = 0; j < num; j++)
				cout << ch[j];
			cout << endl;
		}
		else break;
	}
	delete[] ch;
	return 0;
}
bool JAM(char ch[])
{
	if (ch[num - 1] != last)
	{
		ch[num - 1]++;
		return true;
	}
	for (int i = num - 2; i >= 0; i--)
	{
		if (ch[i] + 1 != ch[i + 1])
		{
			ch[i]++;
			for (int j = i + 1; j < num; j++)
				ch[j] = ch[j - 1] + 1;
			return true;
		}
	}
	return false;
}