#include <iostream>
#include <limits.h>
using namespace std;
struct Data
{
	long long bit1;
	long long bit2;
};
int main()
{
	int n; cin >> n;
	Data *data = new Data[n];
	data[0].bit1 = 0; data[1].bit1 = 1;
	for (int i = 2; i < n; i++)
		data[i] = i*(data[i - 1] + data[i - 2]);
	if (data[n - 1].bit2 != 0) cout << data[n - 1].bit2 << data[n - 1].bit1 << endl;
	else cout << data[n - 1].bit1 << endl;
	delete[] data;
	return 0;
}