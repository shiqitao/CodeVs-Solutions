#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
int row, column;
bool *data;
bool *ifSearch;
int search(int x, int y);
int main()
{
	cin >> column >> row;
	vector<int> result;
	while (row != 0)
	{
		data = new bool[row*column];
		int x, y;
		char ch;
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < column; j++)
			{
				cin >> ch;
				if (ch == '.') data[i*column + j] = true;
				else if (ch == '#') data[i*column + j] = false;
				else
				{
					data[i*column + j] = true;
					x = i; y = j;
				}
			}
		}
		ifSearch = new bool[row*column];
		memset(ifSearch, false, sizeof(bool)*row*column);
		result.push_back(search(x, y));
		delete[] data;
		delete[] ifSearch;
		cin >> column >> row;
	}
	for (int i = 0; i < result.size(); i++)
		cout << result[i] << endl;
	vector<int>().swap(result);
	return 0;
}
int search(int x, int y)
{
	int num = 1;
	ifSearch[x*column + y] = true;
	if (x != 0 && !ifSearch[(x - 1)*column + y] && data[(x - 1)*column + y]) num += search(x - 1, y);
	if (x != row - 1 && !ifSearch[(x + 1)*column + y] && data[(x + 1)*column + y]) num += search(x + 1, y);
	if (y != 0 && !ifSearch[x*column + y - 1] && data[x*column + y - 1]) num += search(x, y - 1);
	if (y != column - 1 && !ifSearch[x*column + y + 1] && data[x*column + y + 1]) num += search(x, y + 1);
	return num;
}