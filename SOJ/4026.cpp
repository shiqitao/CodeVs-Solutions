/**********
ID:4026
Author:Qitao Shi
Date:2017-09-25
**********/
#include <iostream>
using namespace std;
#define Offset 29
int main()
{
	char a[4];
	cin >> a;
	if (a[3] > '9' || a[3] < '0')
	{
		cout << "Error!";
	}
	else
	{
		a[0] += Offset; a[1] += Offset; a[2] += Offset; a[3] += Offset;
		cout << a[0] << a[1] << a[2] << a[3];
	}
	return 0;
}