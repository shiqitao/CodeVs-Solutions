#include <iostream>
using namespace std;
int main()
{
	int paid; cin >> paid;
	int cost; cin >> cost;
	int chargeSum = paid - cost;
	cout << chargeSum << endl;
	int charge[6];
	int money[6] = { 100, 50, 20, 10, 5, 1 };
	int chargeMin = -1;
	for (int i = 0; i < 6; i++)
	{
		charge[i] = chargeSum / money[i];
		chargeSum %= money[i];
		if (charge[i]!=0)
			chargeMin = i;
	}
	for (int i = 0; i < chargeMin; i++)
	{
		if (charge[i] != 0)
			cout << money[i] << "*" << charge[i] << "+";
	}
	cout << money[chargeMin] << "*" << charge[chargeMin] << "=" << paid - cost << endl;
	return 0;
}