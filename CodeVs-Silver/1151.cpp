#include <iostream>
using namespace std;
struct Volunteer
{
	int id;
	int grade;
};
int main()
{
	int n, m; cin >> n >> m;
	Volunteer *volunteer = new Volunteer[n];
	for (int i = 0; i < n; i++)
		cin >> volunteer[i].id >> volunteer[i].grade;
	Volunteer temp;
	for (int i = 0; i < n; i++)
	{
		for (int j = n - 1; j > i; j--)
		{
			if (volunteer[j].grade > volunteer[j - 1].grade || (volunteer[j].grade == volunteer[j - 1].grade && volunteer[j].id < volunteer[j - 1].id))
			{
				temp = volunteer[j];
				volunteer[j] = volunteer[j - 1];
				volunteer[j - 1] = temp;
			}
		}
	}
	int num = int(m*1.5);
	while (volunteer[num].grade == volunteer[num - 1].grade) num++;
	cout << volunteer[num - 1].grade << " " << num << endl;
	for (int i = 0; i < num; i++)
		cout << volunteer[i].id << " " << volunteer[i].grade << endl;
	return 0;
}