#include <iostream>
#include <map>
using namespace std;
int main()
{
	int n; cin >> n;
	map<int, int>data;
	int *studentID = new int[n];
	int temp;
	int num = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		map<int, int>::iterator it = data.find(temp);
		if (it == data.end())
		{
			data.insert(pair<int, int>(temp, num));
			studentID[num] = temp;
			num++;
		}
	}
	data.clear();
	cout << num << endl;
	for (int i = 0; i < num; i++)
	{
		for (int j = num - 1; j > i; j--)
		{
			if (studentID[j] < studentID[j - 1])
			{
				temp = studentID[j];
				studentID[j] = studentID[j - 1];
				studentID[j - 1] = temp;
			}
		}
		cout << studentID[i] << " ";
	}
	cout << endl;
	delete[] studentID;
	return 0;
}