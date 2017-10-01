#include <iostream>
#include <cstring>
#include <limits.h>
using namespace std;
struct Trace
{
	bool ifnew;
	int start;
	int end;
};
int main()
{
	int n; cin >> n;
	int *data = new int[n*n];
	for (int i = 0; i < n*n; i++)
		cin >> data[i];
	bool *state = new bool[n];
	memset(state, false, sizeof(bool)*n);
	state[0] = true;
	Trace *trace = new Trace[n];
	memset(trace, 0, sizeof(Trace)*n);
	int min, num = 0, sum = 0;
	for (int i = 1; i < n; i++)
	{
		min = INT_MAX;
		for (int j = 0; j < n; j++)
		{
			if (state[j])
			{
				for (int k = 1; k < n; k++)
				{
					if (!state[k] && data[j*n + k] < min)
					{
						min = data[j*n + k];
						trace[i].start = j;
						trace[i].end = k;
					}
				}
			}
		}
		state[trace[i].end] = true;
		if (min != 0)
		{
			num++;
			trace[i].ifnew = true;
			sum += min;
		}
	}
	cout << num << endl;
	for (int i = 1; i < n; i++)
	{
		if (trace[i].ifnew && trace[i].start < trace[i].end)
			cout << trace[i].start + 1 << " " << trace[i].end + 1 << endl;
		else if (trace[i].ifnew && trace[i].start > trace[i].end)
			cout << trace[i].end + 1 << " " << trace[i].start + 1 << endl;
	}
	cout << sum << endl;
	delete[] data;
	delete[] state;
	delete[] trace;
	return 0;
}