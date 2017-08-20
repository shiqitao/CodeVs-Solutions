#include <iostream>
using namespace std;
int main()
{
	int n; cin >> n;
	int score = 0;
	while (n != 1)
	{
		if (n % 2)
			n = n * 3 + 1;
		else
			n /= 2;
		score++;
	}
	cout << score << endl;
	return 0;
}