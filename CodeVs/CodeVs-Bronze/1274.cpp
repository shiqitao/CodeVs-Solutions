#include <iostream>
using namespace std;
int main()
{
	int limit;
	int recorded;
	cout << "Enter the speed limit: ";
	cin >> limit;
	cout << "Enter the recorded speed of the car: ";
	cin >> recorded;
	if (recorded <= limit)
		cout << "Congratulations, you are within the speed limit" << endl;
	else if (recorded - limit <= 20)
		cout << "You are speeding and your fine is $ 100" << endl;
	else if (recorded - limit <= 30)
		cout << "You are speeding and your fine is $ 270" << endl;
	else
		cout << "You are speeding and your fine is $ 500" << endl;
	return 0;
}