#include <iostream>
using namespace std;
int main()
{
	int n; cin >> n;
	int temp1, temp2, temp3;
	int *grade = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> temp1 >> temp2 >> temp3;
		grade[i] = ((temp1 + temp2 + temp3) * 100 + temp1)*n + n - i - 1;
	}
	int temp;
	for (int i = 0; i < n; i++)
	{
		for (int j = n - 1; j > i; j--)
		{
			if (grade[j] > grade[j - 1])
			{
				temp = grade[j];
				grade[j] = grade[j - 1];
				grade[j - 1] = temp;
			}
		}
	}
	for (int i = 0; i < 5; i++)
		cout << n - grade[i] % n << " " << grade[i] / n / 100 << endl;
	delete[] grade;
	return 0;
}