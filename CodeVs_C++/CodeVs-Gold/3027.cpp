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
	int price;
};
bool cmp(Line line1, Line line2);
int main()
{
	int N; cin >> N;
	Line *data = new Line[N];
	for (int i = 0; i < N; i++)
		cin >> data[i].left >> data[i].right >> data[i].price;
	sort(data, data + N, cmp);
	int *DP = new int[N];
	for (int i = 0; i < N; i++)
		DP[i] = data[i].price;
	int max = DP[0];
	for (int i = 1; i < N; i++)
	{
		for (int j = i - 1; j >= 0; j--)
		{
			if (data[i].left >= data[j].right && DP[i] < DP[j] + data[i].price)
				DP[i] = DP[j] + data[i].price;
		}
		max = MAX(max, DP[i]);
	}
	cout << max << endl;
	delete[] data;
	delete[] DP;
	return 0;
}
bool cmp(Line line1, Line line2)
{
	if (line1.right != line2.right) return line1.right < line2.right;
	else return line1.left < line2.left;
}