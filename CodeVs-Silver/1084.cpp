#include <iostream>
#include <vector>
using namespace std;
struct num
{
	int num1;
	int num2;
};
int main()
{
	char ch;
	cin >> ch;
	int num1 = 0, num2 = 0, num3 = 0, num4 = 0;
	int n1 = 0;
	int n2 = 0;
	vector<num> data1;
	vector<num> data2;
	while (ch != 'E')
	{
		if (ch == 'W') { num1++, num3++; }
		else if (ch == 'L') { num2++; num4++; }
		if ((num1 >= 11 && num1 - num2 >= 2) || (num2 >= 11 && num2 - num1 >= 2))
		{
			num temp{ num1, num2 };
			data1.push_back(temp);
			num1 = 0;
			num2 = 0;
			n1++;
		}
		if ((num3 >= 21 && num3 - num4 >= 2) || (num4 >= 21 && num4 - num3 >= 2))
		{
			num temp{ num3, num4 };
			data2.push_back(temp);
			num3 = 0;
			num4 = 0;
			n2++;
		}
		cin >> ch;
	}
	for (int i = 0; i < n1; i++)
		cout << data1[i].num1 << ":" << data1[i].num2 << endl;
	cout << num1 << ":" << num2 << endl << endl;
	for (int i = 0; i < n2; i++)
		cout << data2[i].num1 << ":" << data2[i].num2 << endl;
	cout << num3 << ":" << num4 << endl << endl;
	return 0;
}