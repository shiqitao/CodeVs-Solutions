#include <iostream>
using namespace std;
int main()
{
	int data[10]; int limit;
	for (int i = 0; i < 10; i++)
		cin >> data[i];
	cin >> limit; limit += 30;
	int num = 0;
	for (int i = 0; i < 10; i++)
	{
		if (data[i] <= limit)
			num++;
	}
	cout << num << endl;
	return 0;
}