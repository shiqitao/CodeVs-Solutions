#include<iostream>  
#include<cmath>  
using namespace std;
int main(void)
{
	double n, p;
	while (cin >> n >> p)
		cout << pow(p, 1.0 / n) << endl;
	return 0;
}