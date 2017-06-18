#include <iostream>
#include <string>
using namespace std;
bool cmp(bool *square1, bool *square2, int n);
bool change1(bool *oldSquare, bool *newSquare, int n);
bool change2(bool *oldSquare, bool *newSquare, int n);
bool change3(bool *oldSquare, bool *newSquare, int n);
bool change4(bool *oldSquare, bool *newSquare, int n);
bool change5(bool *oldSquare, bool *newSquare, int n);
bool change6(bool *oldSquare, bool *newSquare, int n);
int main()
{
	int n; cin >> n;
	bool *oldSquare = new bool[n * n];
	bool *newSquare = new bool[n * n];
	string temp;
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		for (int j = 0; j < n; j++)
		{
			if (temp[j] == '@') oldSquare[i * n + j] = 1;
			else oldSquare[i * n + j] = 0;
		}
	}
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		for (int j = 0; j < n; j++)
		{
			if (temp[j] == '@') newSquare[i * n + j] = 1;
			else newSquare[i * n + j] = 0;
		}
	}
	if (change1(oldSquare, newSquare, n))
		cout << 1 << endl;
	else if (change2(oldSquare, newSquare, n))
		cout << 2 << endl;
	else if (change3(oldSquare, newSquare, n))
		cout << 3 << endl;
	else if (change4(oldSquare, newSquare, n))
		cout << 4 << endl;
	else if (change5(oldSquare, newSquare, n))
		cout << 5 << endl;
	else if (change6(oldSquare, newSquare, n))
		cout << 6 << endl;
	else
		cout << 7 << endl;
	delete[] oldSquare;
	delete[] newSquare;
	return 0;
}
bool cmp(bool *square1, bool *square2, int n)
{
	for (int i = 0; i < n * n; i++)
	{
		if (square1[i] != square2[i])
			return false;
	}
	return true;
}
bool change1(bool *oldSquare, bool *newSquare, int n)
{
	bool *tempSquare = new bool[n *n];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			tempSquare[j * n + n - 1 - i] = oldSquare[i * n + j];
	}
	bool ifSame = cmp(tempSquare, newSquare, n);
	delete[] tempSquare;
	return ifSame;
}
bool change2(bool *oldSquare, bool *newSquare, int n)
{
	bool *tempSquare = new bool[n *n];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			tempSquare[(n - 1 - i) * n + n - 1 - j] = oldSquare[i * n + j];
	}
	bool ifSame = cmp(tempSquare, newSquare, n);
	delete[] tempSquare;
	return ifSame;
}
bool change3(bool *oldSquare, bool *newSquare, int n)
{
	bool *tempSquare = new bool[n *n];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			tempSquare[(n - 1 - j) * n + i] = oldSquare[i * n + j];
	}
	bool ifSame = cmp(tempSquare, newSquare, n);
	delete[] tempSquare;
	return ifSame;
}
bool change4(bool *oldSquare, bool *newSquare, int n)
{
	bool *tempSquare = new bool[n *n];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			tempSquare[i * n + n - 1 - j] = oldSquare[i * n + j];
	}
	bool ifSame = cmp(tempSquare, newSquare, n);
	delete[] tempSquare;
	return ifSame;
}
bool change5(bool *oldSquare, bool *newSquare, int n)
{
	bool *tempSquare = new bool[n *n];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			tempSquare[i * n + n - 1 - j] = oldSquare[i * n + j];
	}
	bool ifSame = change1(tempSquare, newSquare, n) | change2(tempSquare, newSquare, n) | change3(tempSquare, newSquare, n);
	delete[] tempSquare;
	return ifSame;
}
bool change6(bool *oldSquare, bool *newSquare, int n)
{
	return cmp(oldSquare, newSquare, n);
}