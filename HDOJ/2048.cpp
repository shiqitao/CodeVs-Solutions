//Å·À­´íÅÅ¹«Ê½£ºD(n) = n![(-1)^2/2! + ¡­ + (-1)^(n-1)/(n-1)! + (-1)^n/n!]
#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	long long data[21] = { 0, 0, 1 };
	long long sum[21] = { 0, 1 };
	for (int i = 3; i < 21; i++)
		data[i] = (data[i - 1] + data[i - 2]) * (i - 1);
	for (int i = 2; i < 21; i++)
		sum[i] = sum[i - 1] * i;
	int n; cin >> n;
	for (int i = 0; i < n; i++)
	{
		int m; cin >> m;
		cout << setiosflags(ios::fixed) << setprecision(2) << (double)data[m] * 100 / sum[m] << "%" << endl;
	}
	return 0;
}