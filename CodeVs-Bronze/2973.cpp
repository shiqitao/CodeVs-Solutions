#include <iostream>
using namespace std;
int main()
{
	int n; cin >> n;
	int *data = new int[n];
	int max = 0;
	int index;
	int temp1, temp2;
	for (int i = 0; i < n; i++)
	{
		cin >> temp1 >> temp2;
		data[i] = temp1 * temp2;
		if (max <= data[i])
		{
			max = data[i];
			index = i;
		}
	}
	for (int i = 0; i < n; i++)
		cout << data[i] << endl;
	cout << index + 1 << endl;
	delete[] data;
	return 0;
}