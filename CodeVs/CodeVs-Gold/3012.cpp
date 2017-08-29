#include <iostream>
#include <iomanip>
#include <cstring>
#include <stdlib.h>
#include <time.h>
using namespace std;
#define MIN(x,y) x<y?x:y
#define MAX(x,y) x>y?x:y
struct Line
{
	int left;
	int right;
	int price;
};
bool cmp(Line line1, Line line2);
void swap(Line &line1, Line &line2);
void quickSort(Line data[], int start, int end);
int pivot(Line data[], int start, int end);
int divide(const Line data[], int start, int end, const int num);
int main()
{
	ios::sync_with_stdio(false);
	int N; cin >> N;
	Line *data = new Line[N];
	for (int i = 0; i < N; i++)
		cin >> data[i].left >> data[i].right >> data[i].price;
	srand((unsigned)time(0));
	quickSort(data, 0, N - 1);
	long long *DP = new long long[N];	// 前i个线段的最大价值
	DP[0] = data[0].price;
	for (int i = 1; i < N; i++)
	{
		int div = divide(data, 0, i - 1, data[i].left);
		if (div != -1) DP[i] = MAX(DP[i - 1], DP[div] + data[i].price);
		else DP[i] = MAX(DP[i - 1], data[i].price);
	}
	cout << DP[N - 1] << endl;
	delete[] data;
	delete[] DP;
	return 0;
}
bool cmp(Line line1, Line line2)
{
	return line1.right <= line2.right;
}
void swap(Line &line1, Line &line2)
{
	Line temp = line1;
	line1 = line2;
	line2 = temp;
}
void quickSort(Line data[], int start, int end)
{
	int key;
	if (start < end)
	{
		key = pivot(data, start, end);
		quickSort(data, start, key - 1);
		quickSort(data, key + 1, end);
	}
}
int pivot(Line data[], int start, int end)
{
	int key = start + rand() % (end - start + 1);
	swap(data[key], data[start]);
	Line pivotkey = data[start];
	while (start < end)
	{
		while (start < end && cmp(pivotkey, data[end])) end--;
		swap(data[start], data[end]);
		while (start < end && cmp(data[start], pivotkey)) start++;
		swap(data[start], data[end]);
	}
	return start;
}
int divide(const Line data[], int start, int end, const int num)
{
	while (start + 1 < end)
	{
		int mid = (start + end) / 2;
		if (data[mid].right <= num) start = mid;
		else end = mid - 1;
	}
	if (data[end].right <= num) return end;
	if (data[start].right <= num) return start;
	return -1;
}