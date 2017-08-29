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
int main()
{
	int N; cin >> N;
	Line *data = new Line[N];
	int temp1, temp2;
	for (int i = 0; i < N; i++)
	{
		cin >> temp1 >> temp2;
		data[i].left = MIN(temp1, temp2);
		data[i].right = MAX(temp1, temp2);
	}
	sort(data, data + N, cmp);
	int *DP = new int[N];
	memset(DP, 0, sizeof(int)*N);
	int max = 0;
	for (int i = 1; i < N; i++)
	{
		for (int j = i - 1; j >= 0; j--)
		{
			if (data[i].left >= data[j].right && DP[i] <= DP[j])
				DP[i] = DP[j] + 1;
		}
		max = MAX(max, DP[i]);
	}
	cout << max + 1 << endl;
	delete[] data;
	delete[] DP;
	return 0;
}
bool cmp(Line line1, Line line2)
{
	if (line1.right != line2.right) return line1.right < line2.right;
	else return line1.left < line2.left;
}