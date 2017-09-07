#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	unsigned int n, m, a; cin >> n >> m >> a;
	n = ceil(double(n) / a);
	m = ceil(double(m) / a);
	unsigned long long result = (unsigned long long)n*m;
	cout << result << endl;
	return 0;
}