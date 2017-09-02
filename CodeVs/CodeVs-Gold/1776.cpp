#include <iostream>
#include <string>
using namespace std;
int main()
{
	string str1, str2, str3; cin >> str1 >> str2 >> str3;
	int n = str1.size();
	for (int i = 0; i < n; i++)
	{
		if (str1[i] <= 'Z') str1[i] += 32;
		if (str2[i] <= 'Z') str2[i] += 32;
		if (str3[i] <= 'Z') str3[i] += 32;
	}


	return 0;
}