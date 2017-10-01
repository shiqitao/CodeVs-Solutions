#include <iostream>
#include <cmath>
using namespace std;
bool ifPalindrome(int num, int n);
void print(int num, int n);
int main()
{
	int n; cin >> n;
	for (int i = 1; i <= 300; i++)
	{
		if (ifPalindrome(i, n))
		{
			print(i, n); cout << " ";
			print(i * i, n); cout << endl;
		}
	}
	return 0;
}
bool ifPalindrome(int num, int n)
{
	long long numNew = 0;
	int tempNum = num * num;
	int temp;
	int power = 0;
	while (tempNum != 0)
	{
		temp = tempNum % n;
		numNew = numNew * n + temp;
		tempNum /= n;
		power++;
	}
	if (numNew == num * num) return true;
	else return false;
}
void print(int num, int n)
{
	int printNum[10];
	int numPrint = 0;
	while (num != 0)
	{
		printNum[numPrint] = num % n;
		num = num / n;
		numPrint++;
	}
	for (int i = numPrint - 1; i >= 0; i--)
	{
		if (printNum[i] < 10)
			cout << printNum[i];
		else
		{
			switch (printNum[i])
			{
			case 10:{cout << "A"; break; }
			case 11:{cout << "B"; break; }
			case 12:{cout << "C"; break; }
			case 13:{cout << "D"; break; }
			case 14:{cout << "E"; break; }
			case 15:{cout << "F"; break; }
			case 16:{cout << "G"; break; }
			case 17:{cout << "H"; break; }
			case 18:{cout << "I"; break; }
			case 19:{cout << "J"; break; }
			case 20:{cout << "K"; break; }
			}
		}
	}
}