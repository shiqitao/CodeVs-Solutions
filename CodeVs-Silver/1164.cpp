#include <iostream>
#include <map>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	int n, in;
	cin >> n;
	map<int, int>hash;
	for (int i = 0; i<n; ++i)
	{
		cin >> in;
		hash[in]++;
	}
	for (map<int, int>::iterator it = hash.begin(); it != hash.end(); ++it)
		cout << (*it).first << ' ' << (*it).second << endl;
	return 0;
}