#include <iostream>
#include <vector>
using namespace std;
int main()
{
	vector<int> result;
	int n; cin >> n;
	while (n != 0)
	{
		int data[3] = { 1, 0, 0 };
		int temp;
		for (int i = 1; i < n; i++)
		{
			temp = data[0];
			data[0] += data[1];
			data[1] = data[2];
			data[2] = temp;
		}
		result.push_back(data[0] + data[1] + data[2]);
		cin >> n;
	}
	for (int i = 0; i < result.size(); i++)
		cout << result[i] << endl;
	return 0;
}