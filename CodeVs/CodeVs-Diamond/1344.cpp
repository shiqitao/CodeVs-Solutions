#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include <limits.h>
#include <float.h>
#include <cmath>
#include <time.h>
using namespace std;
#define MIN(x,y) ((x)<(y)?(x):(y))
#define d(x,y) distance[order[x]*n+order[y]]
struct Node
{
	int x, y;
};
bool check(int order[], double distance[], int n);
void swap(int order[], int i, int j);
int main()
{
	int n; cin >> n;
	Node *node = new Node[n];
	for (int i = 0; i < n; i++)
		cin >> node[i].x >> node[i].y;
	double *distance = new double[n*n];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			distance[i*n + j] = sqrt((node[i].x - node[j].x)*(node[i].x - node[j].x) + (node[i].y - node[j].y)*(node[i].y - node[j].y));
	}
	int *order = new int[n];
	for (int i = 0; i < n; i++)
		order[i] = i;
	srand((unsigned)time(NULL));
	double result = DBL_MAX;
	for (int p = 0; p < 500; p++)
	{
		int rank, temp;
		for (int i = 0; i < n; i++)
		{
			rank = rand() % n;
			temp = order[i];
			order[i] = order[rank];
			order[rank] = temp;
		}
		while (!check(order, distance, n))
		{
			for (int i = 1; i < n - 2; i++)
			{
				for (int j = i + 1; j < n - 1; j++)
				{
					if (d(i - 1, i) + d(j, j + 1)>d(i - 1, j) + d(i, j + 1))
					{
						for (int k = 0; k < (j - i + 1) / 2; k++)
							swap(order, i + k, j - k);
					}
				}
			}
		}
		double sum = 0;
		for (int i = 1; i < n; i++)
			sum += d(i - 1, i);
		result = MIN(result, sum);
	}
	cout << setiosflags(ios::fixed) << setprecision(2) << result << endl;
	delete[] node;
	delete[] distance;
	delete[] order;
	return 0;
}
bool check(int order[], double distance[], int n)
{
	for (int i = 1; i < n - 1; i++)
	{
		for (int j = i + 1; j < n - 1; j++)
		{
			if (d(i - 1, i) + d(j, j + 1)>d(i - 1, j) + d(i, j + 1))
				return false;
		}
	}
	return true;
}
void swap(int order[], int i, int j)
{
	int temp = order[i];
	order[i] = order[j];
	order[j] = temp;
}