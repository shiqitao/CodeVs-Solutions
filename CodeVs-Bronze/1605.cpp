#include <iostream>
#include <limits.h>
using namespace std;
struct Block
{
	int width;
	int height;
};
int main()
{
	int n; cin >> n;
	Block *block = new Block[n];
	for (int i = 0; i < n; i++)
		cin >> block[i].width >> block[i].height;
	int square; cin >> square;
	int sumWidth;
	int minHeight = INT_MAX;
	for (int i = 0; i < n; i++)
	{
		sumWidth = block[i].width;
		int j = i + 1;
		while (sumWidth < square && j < n)
		{
			if (block[i].height < block[j].height)
				block[i].height = block[j].height;
			sumWidth += block[j].width;
			j++;
		}
		if (sumWidth >= square && minHeight > block[i].height)
			minHeight = block[i].height;
	}
	cout << minHeight + square << endl;
	delete[] block;
	return 0;
}