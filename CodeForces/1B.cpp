#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
	int n; cin >> n;
	for (int i = 0; i < n; i++)
	{
		string str; cin >> str;
		string result;
		int length = str.length();
		bool type = 1;
		if (str[0] == 'R' && str[1] <= '9' && str[1] >= '0')
		{
			int k = 2;
			while (k != length && str[k] <= '9' && str[k] >= '0') k++;
			if (k != length) type = 0;
		}
		if (type)
		{
			int k = 0;
			while (str[k] > '9') k++;
			string temp1 = str.substr(0, k);
			string temp2 = str.substr(k, length - k);
			result = 'R' + temp2 + 'C';
			int column = 0;
			for (int j = 0; j < temp1.length(); j++)
				column = column * 26 + int(temp1[j] - 'A') + 1;
			cout << result << column << endl;
		}
		else
		{
			int div = str.find('C');
			string temp1 = str.substr(1, div - 1);
			string temp2 = str.substr(div + 1, length - div - 1);
			int column = 0;
			for (int j = 0; j < temp2.length(); j++)
				column = column * 10 + int(temp2[j] - '0');
			while (column != 0)
			{
				column--;
				result += 'A' + column % 26;
				column /= 26;
			}
			reverse(result.begin(), result.end());
			result += temp1;
			cout << result << endl;
		}
	}
	return 0;
}