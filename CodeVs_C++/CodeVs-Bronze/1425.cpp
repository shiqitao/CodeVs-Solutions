#include <iostream>
#include <string>
using namespace std;
void getNext(string str, int next[]);
bool ifSubstring(string str, string temp, int next[]);
int main()
{
	int n; cin >> n;
	string *data = new string[n];
	int minLength = INT_MAX;
	int minIndex;
	for (int i = 0; i < n; i++)
	{
		cin >> data[i];
		if (data[i].length() < minLength)
		{
			minLength = data[i].length();
			minIndex = i;
		}
	}
	if (minIndex != 0)
	{
		string temp = data[0];
		data[0] = data[minIndex];
		data[minIndex] = temp;
	}
	int MLS = 0;
	string temp;
	int maxi = 0, maxj = 0, max = 0;
	for (int i = 0; i < minLength - 1; i++)
	{
		temp = data[0].substr(i, minLength);
		int *next = new int[minLength - i];
		getNext(temp, next);
		for (int j = i + 1; j <= minLength; j++)
		{
			temp = data[0].substr(i, j);
			int k;
			for (k = 1; k < n; k++)
			{
				if (ifSubstring(data[k], temp, next))
					continue;
				break;
			}
			if (k == n && j - i>max)
			{
				max = j - i;
				maxi = i; maxj = j;
			}
		}
		delete[] next;
	}
	cout << data[0].substr(maxi, maxj) << endl;
	delete[] data;
	return 0;
}
void getNext(string str, int next[])
{
	next[0] = -1;
	int i = -1;
	int j = 0;
	while (j < str.length() - 1)
	{
		//p[k]表示前缀，p[j]表示后缀  
		if (i == -1 || str[i] == str[j])
		{
			i++;
			j++;
			if (str[i] != str[j])
				next[j] = i;
			else
				next[j] = next[i];
		}
		else
		{
			i = next[i];
		}
	}
}
bool ifSubstring(string str, string temp, int next[])
{
	int i = 0, j = 0;
	int strLen = str.length();
	int tempLen = temp.length();
	while (i < strLen && j < tempLen)
	//while (i < str.length() && j < temp.length())
	{
		if (j == -1 || str[i] == temp[j])
		{
			i++;
			j++;
		}
		else
			j = next[j];
	}
	if (j == temp.length()) return true;
	else return false;
}