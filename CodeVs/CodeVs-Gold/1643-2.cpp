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
	for (int i = 0; i < N; i++)
		cin >> data[i].left >> data[i].right;
	sort(data, data + N, cmp);
	int last = data[0].right;
	int max = 1;
	for (int i = 1; i < N; i++)
	{
		if (data[i].left >= last)
		{
			last = data[i].right;
			max++;
		}
	}
	cout << max << endl;
	delete[] data;
	return 0;
}
bool cmp(Line line1, Line line2)
{
	if (line1.right != line2.right) return line1.right < line2.right;
	else return line1.left < line2.left;
}