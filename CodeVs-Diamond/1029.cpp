#include <iostream>
#include <string>
using namespace std;
int count(string DLR, string LRD);
int main()
{
	string DLR, LRD;
	cin >> DLR >> LRD;
	cout << count(DLR, LRD) << endl;
	return 0;
}
int count(string DLR, string LRD)
{
	char c = DLR[1];
	int length = DLR.length();
	if (length == 1) return 1;
	int temp = LRD.find(c);
	string DLRNEW, LRDNEW;
	if (temp == length - 2)
	{
		DLRNEW.assign(DLR, 1, length - 1);
		LRDNEW.assign(LRD, 0, length - 1);
		return 2 * count(DLRNEW, LRDNEW);
	}
	else
	{
		DLRNEW.assign(DLR, 1, temp + 1);
		LRDNEW.assign(LRD, 0, temp + 1);
		int count1 = count(DLRNEW, LRDNEW);
		DLRNEW.assign(DLR, temp + 2, length - temp - 2);
		LRDNEW.assign(LRD, temp + 1, length - temp - 2);
		int count2 = count(DLRNEW, LRDNEW);
		return count1*count2;
	}
}