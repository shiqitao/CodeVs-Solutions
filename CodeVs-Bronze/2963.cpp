#include <iostream>
#include <map>
using namespace std;
int main()
{
	map <int, int>myMap;
	int n; cin >> n;
	int temp;
	int m = 0;
	pair<map<int, int>::iterator, bool> Insert_Pair;
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		Insert_Pair = myMap.insert(pair<int, int>(temp, m));
		if (Insert_Pair.second == true)
			m++;
	}
	int *data = new int[m];
	map<int, int>::iterator it;
	it = myMap.begin();
	while (it != myMap.end())
	{
		data[it->second] = it->first;
		it++;
	}
	cout << m << endl;
	for (int i = 0; i < m; i++)
	{
		for (int j = m - 1; j >0; j--)
		{
			if (data[j] < data[j - 1])
			{
				int temp = data[j];
				data[j] = data[j - 1];
				data[j - 1] = temp;
			}
		}
		cout << data[i] << " ";
	}
	cout << endl;
	delete[] data;
	return 0;
}