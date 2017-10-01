#include <iostream>
#include <string>
using namespace std;
int main()
{
	string data;
	cin >> data;
	int temp = 0;
	int max = 0;
	for (int i = 0; i < data.size(); i++)
	{
		if (data[i] == 'K')
			temp++;
		else
		{
			if (temp > max)
				max = temp;
			temp = 0;
		}
	}
	if (temp > max)
		max = temp;
	switch (max)
	{
	case 0:cout << "You are a Foolish Man" << endl; break;
	case 1:cout << "You are a Foolish Man" << endl; break;
	case 2:cout << "You are a Foolish Man" << endl; break;
	case 3:cout << "You are on a Killing Spree" << endl; break;
	case 4:cout << "You are Dominating" << endl; break;
	case 5:cout << "You have a Mega-Kill" << endl; break;
	case 6:cout << "You are Unstoppable" << endl; break;
	case 7:cout << "You are Wicked Sick" << endl; break;
	case 8:cout << "You have a M-m-m-m....Monster Kill" << endl; break;
	case 9:cout << "You are Godlike" << endl; break;
	default:cout << "You are Beyond Godlike (Somebody kill him!)" << endl; break;
	}
	return 0;
}