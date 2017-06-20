#include <iostream>
#include <string>
#include <map>
using namespace std;
int main()
{
	int n; cin >> n;
	string data[9][9];
	map <int, char> IntToChar;
	map <char, int> CharToInt;
	bool temp = true;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> data[i][j];
			if (data[i][j].size() != 1 && temp)
			{
				IntToChar[1] = data[i][j].c_str()[0];
				CharToInt.insert(pair <char, int>(data[i][j].c_str()[0], 1));
				//CharToInt[data[i][j].c_str()[0]] == 1;
				temp = false;
			}
			else if (data[i][j].size() != 1 && !temp)
			{
				if (data[i][j].c_str()[0] != IntToChar[1])
				{
					cout << "ERROR!" << endl;
					return 0;
				}
			}
		}
	}
	int index;
	for (int i = 1; i < n; i++)
	{
		if (data[0][i].c_str()[0] == IntToChar[1])
		{
			index = i;
			break;
		}
	}
	IntToChar[2] = data[index][index].c_str()[0];
	CharToInt.insert(pair <char, int>(data[index][index].c_str()[0], 2));
	for (int i = 3; i < n - 1; i++)
	{
		for (int j = 1; j < n; j++)
		{
			if (data[0][j].c_str()[0] == IntToChar[i - 1])
			{
				IntToChar[i] = data[index][j].c_str()[0];
				CharToInt.insert(pair <char, int>(data[index][j].c_str()[0], i));
				break;
			}
		}
	}
	for (int i = 1; i < n; i++)
	{
		if (data[0][i].c_str()[0] == IntToChar[n - 2])
		{
			IntToChar[0] = data[index][i].c_str()[1];
			CharToInt.insert(pair <char, int>(data[index][i].c_str()[1], 0));
		}
	}
	for (int i = 0; i < n - 1; i++)
	{
		if (CharToInt[IntToChar[i]] != i)
		{
			cout << "ERROR!" << endl;
			return 0;
		}
	}
	int num1, num2, sum;
	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j < n; j++)
		{
			num1 = CharToInt[data[i][0].c_str()[0]];
			num2 = CharToInt[data[0][j].c_str()[0]];
			sum = num1 + num2;
			if (sum < n - 1 && data[i][j].c_str()[0] != IntToChar[sum])
			{
				cout << "ERROR!" << endl;
				return 0;
			}
			else if (sum >= n - 1 && (data[i][j].c_str()[0] != IntToChar[1] || data[i][j].c_str()[1] != IntToChar[sum - n + 1]))
			{
				cout << "ERROR!" << endl;
				return 0;
			}
		}
	}
	for (int i = 1; i < n; i++)
	{
		cout << data[0][i].c_str()[0] << "=" << CharToInt[data[0][i].c_str()[0]] << " ";
	}
	cout << endl << n - 1 << endl;
	return 0;
}