#include <iostream>
using namespace std;
int main()
{
	int n; cin >> n;
	int RY = 0, ry = 0;
	char a, b;
	for (int i = 0; i < n; i++)
	{
		cin >> a >> b;
		if (a == 'S' && b == 'J' || a == 'J' && b == 'B' || a == 'B' && b == 'S')
			ry++;
		else if (b == 'S' && a == 'J' || b == 'J' && a == 'B' || b == 'B' && a == 'S')
			RY++;
	}
	if (RY > ry)
		cout << "RY win" << endl;
	else if (RY < ry)
		cout << "ry win" << endl;
	else
		cout << "RY=ry" << endl;
	return 0;
}