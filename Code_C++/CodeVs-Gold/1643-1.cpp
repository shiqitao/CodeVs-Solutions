#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
#define MIN(x,y) x<y?x:y
#define MAX(x,y) x>y?x:y
struct Line
{
	int left;
	int right;
};
bool cmp(Line line1, Line line2);
int divide(const Line data[], int start, int end, int num);
int main()
{
	int N; cin >> N;
	Line *data = new Line[N];
	for (int i = 0; i < N; i++)
		cin >> data[i].left >> data[i].right;
	sort(data, data + N, cmp);
	int *DP = new int[N];	// 前i个线段的最大k-1
	memset(DP, 0, sizeof(int)*N);
	for (int i = 1; i < N; i++)
	{
		int div = divide(data, 0, i - 1, data[i].left);
		if (div != -1) DP[i] = MAX(DP[div] + 1, DP[i - 1]);
		else DP[i] = DP[i - 1];
	}
	cout << DP[N - 1] + 1 << endl;
	delete[] data;
	delete[] DP;
	return 0;
}
bool cmp(Line line1, Line line2)
{
	if (line1.right != line2.right) return line1.right < line2.right;
	else return line1.left < line2.left;
}
int divide(const Line data[], int start, int end, int num)
{
	if (start + 1 < end)
	{
		int mid = start + (end - start) / 2;
		if (data[mid].right <= num) return divide(data, mid, end, num);
		else return divide(data, start, mid, num);
	}
	if (data[end].right <= num) return end;
	if (data[start].right <= num) return start;
	return -1;
}