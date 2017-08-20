#include <iostream>
#include <cstring>
using namespace std;
int main()
{
	int L, M; cin >> L >> M;
	bool *data = new bool[L + 1];
	memset(data, true, sizeof(bool)*(L + 1));
	int temp1, temp2;
	for (int i = 0; i < M; i++)
	{
		cin >> temp1 >> temp2;
		memset(&data[temp1], false, sizeof(bool)*(temp2 - temp1 + 1));
	}
	int result = 0;
	for (int i = 0; i < L + 1; i++)
		result += data[i];
	cout << result << endl;
	return 0;
}