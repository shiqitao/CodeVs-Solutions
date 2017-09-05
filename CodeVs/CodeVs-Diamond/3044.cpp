#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
struct Rectangle
{
	double x1, x2, y1, y2;
};
int main()
{
	int n; cin >> n;
	while (n != 0)
	{
		Rectangle *rectangle = new Rectangle[n];
		double *x = new double[2 * n];
		double *y = new double[2 * n];
		for (int i = 0; i < n; i++)
		{
			cin >> rectangle[i].x1 >> rectangle[i].y1 >> rectangle[i].x2 >> rectangle[i].y2;
			x[2 * i] = rectangle[i].x1;
			x[2 * i + 1] = rectangle[i].x2;
			y[2 * i] = rectangle[i].y1;
			y[2 * i + 1] = rectangle[i].y2;
		}
		sort(x, x + 2 * n);
		sort(y, y + 2 * n);
		map<double, int> xMap;
		map<double, int> yMap;
		int xNum = 0;
		int yNum = 0;
		int xTemp = -1;
		int yTemp = -1;
		for (int i = 0; i < 2 * n; i++)
		{
			if (x[i] != xTemp)
			{
				xTemp = x[i];
				xMap[xTemp] = xNum;
				x[xNum] = xTemp;
				xNum++;
			}
			if (y[i] != yTemp)
			{
				yTemp = y[i];
				yMap[yTemp] = yNum;
				y[yNum] = yTemp;
				yNum++;
			}
		}
		bool *data = new bool[(yNum - 1)*(xNum - 1)];
		memset(data, false, sizeof(bool)*(yNum - 1)*(xNum - 1));
		for (int i = 0; i < n; i++)
		{
			int x1 = xMap[rectangle[i].x1];
			int x2 = xMap[rectangle[i].x2];
			int y1 = yMap[rectangle[i].y1];
			int y2 = yMap[rectangle[i].y2];
			for (int i = y1; i < y2; i++)
				memset(data + i*(xNum - 1) + x1, true, sizeof(bool)*(x2 - x1));
		}
		double result = 0;
		for (int i = 0; i < yNum - 1; i++)
		{
			for (int j = 0; j < xNum - 1; j++)
			{
				if (data[i*(xNum - 1) + j])
					result += (y[i + 1] - y[i])*(x[j + 1] - x[j]);
			}
		}
		cout << result << endl;
		delete[] rectangle;
		delete[] x;
		delete[] y;
		delete[] data;
		xMap.clear();
		yMap.clear();
	}
	return 0;
}