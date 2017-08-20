#include <iostream>
using namespace std;
int main()
{
	int k; cin >> k;
	bool ifNo = true;
	int sub1;
	int sub2;
	int sub3;
	for (int i = 10000; i <= 30000; i++)
	{
		sub1 = i / 100;
		sub2 = (i % 10000) / 10;
		sub3 = i % 1000;
		if (sub1%k == 0 && sub2%k == 0 && sub3%k == 0)
		{
			ifNo = false;
			cout << i << endl;
		}
	}
	return 0;
}