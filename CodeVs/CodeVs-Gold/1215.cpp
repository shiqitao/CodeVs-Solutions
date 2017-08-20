#include <iostream>
#include <cstring>
using namespace std;
int n;
bool *data;
bool *ifSearch;
bool search(int x, int y);
int main()
{
	int m; cin >> m;
	bool *result = new bool[m];
	for (int i = 0; i < m; i++)
	{
		cin >> n;
		data = new bool[n*n];
		ifSearch = new bool[n*n];
		memset(ifSearch, false, sizeof(bool)*n*n);
		char ch;
		for (int j = 0; j < n*n; j++)
		{
			cin >> ch;
			if (ch == '#') data[j] = false;
			else data[j] = true;
		}
		result[i] = search(0, 0);
		delete[] data;
		delete[] ifSearch;
	}
	for (int i = 0; i < m; i++)
	{
		if (result[i]) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}
bool search(int x, int y)
{
	ifSearch[x*n + y] = true;
	if (x == n - 1 && y == n - 1) return true;
	if (x != n - 1 && data[(x + 1)*n + y] && !ifSearch[(x + 1)*n + y] && search(x + 1, y)) return true;
	if (y != n - 1 && data[x*n + y + 1] && !ifSearch[x*n + y + 1] && search(x, y + 1)) return true;
	if (x != 0 && data[(x - 1)*n + y] && !ifSearch[(x - 1)*n + y] && search(x - 1, y)) return true;
	if (y != 0 && data[x*n + y - 1] && !ifSearch[x*n + y - 1] && search(x, y - 1)) return true;
	return false;
}