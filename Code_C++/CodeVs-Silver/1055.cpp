#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;
struct Color
{
	string color;
	int num;
};
int main()
{
	vector<Color>color;
	map <string, int> colorMap;
	int n; cin >> n;
	int m = 0;
	string str;
	map<string, int >::iterator it;;
	for (int i = 0; i < n; i++)
	{
		cin >> str;
		it = colorMap.find(str);
		if (it == colorMap.end())
		{
			color.push_back({ str, 1 });
			colorMap.insert(pair<string, int>(str, m));
			m++;
		}
		else
			color[it->second].num++;
	}
	cout << m << endl;
	Color tempColor;
	int tempNum = 0;
	for (int i = 0; i < color.size(); i++)
	{
		for (int j = color.size() - 1; j >0; j--)
		{
			if (color[j].num > color[j - 1].num || (color[j].num == color[j - 1].num && color[j].color < color[j - 1].color))
			{
				tempColor = color[j];
				color[j] = color[j - 1];
				color[j - 1] = tempColor;
			}
		}
		if (color[i].num != tempNum)
		{
			tempNum = color[i].num;
			cout << tempNum << endl;
		}
		cout << color[i].color << endl;
	}
	return 0;
}