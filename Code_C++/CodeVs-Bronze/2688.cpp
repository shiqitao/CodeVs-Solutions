#include <iostream>
using namespace std;
int main()
{
	int num; cin >> num;
	int n = 0;
	int HEX[5];
	while (num != 0)
	{

		HEX[n] = num % 16;
		num = num / 16;
		n++;
	}
	for (int i = n - 1; i >= 0; i--)
	{
		switch (HEX[i])
		{
		case 10:cout << "A"; break;
		case 11:cout << "B"; break;
		case 12:cout << "C"; break;
		case 13:cout << "D"; break;
		case 14:cout << "E"; break;
		case 15:cout << "F"; break;
		default:cout << HEX[i]; break;
		}
	}
	cout << endl;
	return 0;
}