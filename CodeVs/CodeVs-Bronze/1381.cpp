#include <iostream>
#include <string>
#include <hash_map>
using namespace std;
struct Person
{
	string name;
	int money;
};
int main()
{
	int n; cin >> n;
	Person *person = new Person[n];
	hash_map<string, int>hash;
	for (int i = 0; i < n; i++)
	{
		cin >> person[i].name;
		hash[person[i].name] = i;
		person[i].money = 0;
	}
	int money, num;
	string name;
	hash_map<string, int>::iterator it;
	for (int i = 0; i < n; i++)
	{
		cin >> name;
		it = hash.find(name);
		if (it != hash.end())
		{
			cin >> money;
			cin >> num;
			if (num == 0)
				continue;
			person[it->second].money -= money / num * num;
			money /= num;
			for (int j = 0; j < num; j++)
			{
				cin >> name;
				it = hash.find(name);
				person[it->second].money += money;
			}
		}
	}
	for (int i = 0; i < n; i++)
		cout << person[i].name << " " << person[i].money << endl;
	delete[] person;
	return 0;
}