#include <iostream>
using namespace std;
int main()
{
	int price;
	float discount;
	cin >> price >> discount;
	price = price * discount / 10;
	price = price % 10 < 5 ? price - price % 10 : price - price % 10 + 10;
	cout << price << endl;
	return 0;
}