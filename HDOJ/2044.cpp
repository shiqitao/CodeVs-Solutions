#include <iostream>
using namespace std;
int main()
{
	int n; cin >> n;
	long long *result = new long long[n];
	for (int i = 0; i < n; i++)
	{
		int start, end; cin >> start >> end;
		end -= start - 1;
		if (end == 2) result[i] = 1;
		else if (end == 3) result[i] = 2;
		else
		{
			long long temp1 = 1;
			long long temp2 = 2;
			long long temp3;
			for (int i = 4; i <= end; i++)
			{
				temp3 = temp1 + temp2;
				temp1 = temp2;
				temp2 = temp3;
			}
			result[i] = temp3;
		}
	}
	for (int i = 0; i < n; i++)
		cout << result[i] << endl;
	delete[] result;
	return 0;
}