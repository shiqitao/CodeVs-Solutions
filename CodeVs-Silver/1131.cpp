#include <iostream>
#include <string>
using namespace std;
int main()
{
	string s, str;
	getline(cin, s);
	getline(cin, str);
	int sum = 0;
	int start = -1;
	int strl = str.length() - s.length() + 1;
	int sl = s.length();
	int i, j;
	for (i = 0; i < strl; i++)
	{
		for (j = 0; j < sl; j++)
		{
			if (str[i + j] != s[j] && str[i + j] != s[j] + 32 && str[i + j] != s[j] - 32)
				break;
		}
		if (j == sl && (i == 0 || str[i - 1] == ' ') && (i == strl - 1 || str[i + j] == ' '))
		{
			sum++;
			if (start == -1) start = i;
		}
	}
	if (sum == 0) cout << -1 << endl;
	else cout << sum << " " << start << endl;
	return 0;
}