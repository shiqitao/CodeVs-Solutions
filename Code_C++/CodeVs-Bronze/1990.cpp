#include <iostream>
using namespace std;
int main()
{
	unsigned long long data[3][3];
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
			cin >> data[i][j];
	}
	unsigned long long max = data[0][0] + data[1][1] + data[2][2];
	max = max >= data[0][0] + data[1][2] + data[2][1] ? max : data[0][0] + data[1][2] + data[2][1];
	max = max >= data[0][1] + data[1][0] + data[2][2] ? max : data[0][1] + data[1][0] + data[2][2];
	max = max >= data[0][1] + data[1][2] + data[2][0] ? max : data[0][1] + data[1][2] + data[2][0];
	max = max >= data[0][2] + data[1][0] + data[2][1] ? max : data[0][2] + data[1][0] + data[2][1];
	max = max >= data[0][2] + data[1][1] + data[2][0] ? max : data[0][2] + data[1][1] + data[2][0];
	cout << max << endl;
	return 0;
}