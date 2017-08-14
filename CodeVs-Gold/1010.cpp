#include <iostream>
#include <cstring>
using namespace std;
int main()
{
	int n, m, x, y;
	cin >> n >> m >> x >> y;
	int *checkerboard = new int[(n + 1)*(m + 1)];
	memset(checkerboard, 0, sizeof(int)*n*m);
	checkerboard[x*(m + 1) + y] = -1;
	if (x >= 2 && y >= 1) checkerboard[(x - 2)*(m + 1) + y - 1] = -1;
	if (x >= 1 && y >= 2) checkerboard[(x - 1)*(m + 1) + y - 2] = -1;
	if (x >= 2 && y <= m - 1) checkerboard[(x - 2)*(m + 1) + y + 1] = -1;
	if (x >= 1 && y <= m - 2) checkerboard[(x - 1)*(m + 1) + y + 2] = -1;
	if (x <= n - 2 && y >= 1) checkerboard[(x + 2)*(m + 1) + y - 1] = -1;
	if (x <= n - 1 && y >= 2) checkerboard[(x + 1)*(m + 1) + y - 2] = -1;
	if (x <= n - 2 && y <= m - 1) checkerboard[(x + 2)*(m + 1) + y + 1] = -1;
	if (x <= n - 1 && y <= m - 2) checkerboard[(x + 1)*(m + 1) + y + 2] = -1;
	checkerboard[0] = 1;
	for (int i = 1; i < m + 1; i++)
	{
		if (checkerboard[i] == -1) checkerboard[i] = 0;
		else checkerboard[i] = checkerboard[i - 1];
	}
	for (int i = 1; i < n + 1; i++)
	{
		if (checkerboard[i*(m + 1)] == -1) checkerboard[i*(m + 1)] = 0;
		else checkerboard[i*(m + 1)] = checkerboard[(i - 1)*(m + 1)];
	}
	for (int i = 1; i < n + 1; i++)
	{
		for (int j = 1; j < m + 1; j++)
		{
			if (checkerboard[i*(m + 1) + j] == -1) checkerboard[i*(m + 1) + j] = 0;
			else checkerboard[i*(m + 1) + j] = checkerboard[(i - 1)*(m + 1) + j] + checkerboard[i*(m + 1) + j - 1];
		}
	}
	cout << checkerboard[(n + 1)*(m + 1) - 1] << endl;
	delete[] checkerboard;
	return 0;
}