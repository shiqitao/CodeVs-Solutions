#include <iostream>
#include <string>
#include <cstring>
#include <limits.h>
#include <cmath>
using namespace std;
bool ifPrime(int n);
int main()
{
	string str; cin >> str;
	int word[26];
	memset(word, 0, sizeof(int)* 26);
	for (int i = 0; i < str.size(); i++)
		word[str[i] - 'a']++;
	int max = INT_MIN;
	int min = INT_MAX;
	for (int i = 0; i < 26; i++)
	{
		if (word[i] != 0)
		{
			if (max < word[i])
				max = word[i];
			if (min > word[i])
				min = word[i];
		}
	}
	int n = max - min;
	if (ifPrime(n))
		cout << "Lucky Word" << endl << n << endl;
	else
		cout << "No Answer" << endl << 0 << endl;
	return 0;
}
bool ifPrime(int n)
{
	if (n == 0 || n == 1)
		return false;
	else if (n == 2 || n == 3)
		return true;
	int stop = sqrt(n);
	for (int i = 2; i <= stop; i++)
	{
		if (n % i == 0)
			return false;
	}
	return true;
}