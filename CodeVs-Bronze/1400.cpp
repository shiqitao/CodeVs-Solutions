#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	int n, m; cin >> n >> m;
	int *data = new int[(n + 2) * (m + 2)];
	memset(data, 0, sizeof(int)* (n + 2) * (m + 2));
	for (int i = 1; i < n + 1; i++)
	{
		for (int j = 1; j < m + 1; j++)
			cin >> data[i * (m + 2) + j];
	}
	int max = INT_MIN;
	int row, column, grade;
	for (int i = 1; i < n + 1; i++)
	{
		for (int j = 1; j < m + 1; j++)
		{
			grade = 0;
			grade -= data[(i - 1) * (m + 2) + j] * data[i * (m + 2) + j] / abs(data[i * (m + 2) + j]);
			grade -= data[(i + 1) * (m + 2) + j] * data[i * (m + 2) + j] / abs(data[i * (m + 2) + j]);
			grade -= data[i * (m + 2) + j - 1] * data[i * (m + 2) + j] / abs(data[i * (m + 2) + j]);
			grade -= data[i * (m + 2) + j + 1] * data[i * (m + 2) + j] / abs(data[i * (m + 2) + j]);
			if (grade > max)
			{
				max = grade;
				row = i;
				column = j;
			}
		}
	}
	cout << row << " " << column << " " << max << endl;
	return 0;
}