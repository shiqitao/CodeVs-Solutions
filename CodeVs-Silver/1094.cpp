#include <iostream>
#include <cmath>
using namespace std;
void LRD(char tree[], int n, int m);
int main()
{
	int n; cin >> n; n = pow(2, n);
	char temp;
	char *tree = new char[n * 2];
	for (int i = n; i < 2 * n; i++)
	{
		cin >> temp;
		tree[i] = temp == '1' ? 'I' : 'B';
	}
	LRD(tree, n, 1);
	return 0;
}
void LRD(char tree[], int n, int m)
{
	if (m >= n)
	{
		cout << tree[m];
		return;
	}
	LRD(tree, n, 2 * m);
	LRD(tree, n, 2 * m + 1);
	if (tree[2 * m] == tree[2 * m + 1]) tree[m] = tree[2 * m];
	else tree[m] = 'F';
	cout << tree[m];
}