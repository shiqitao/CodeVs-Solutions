#include <iostream>
#include <iomanip>
using namespace std;
int partition(double data[], int start, int end, double *key);
int main()
{
	int n, k;
	cin >> n >> k;
	k--;
	double *GPA = new double[n];
	double GPT;
	int fraction;
	for (int i = 0; i < n; i++)
	{
		cin >> GPT >> fraction;
		GPA[i] = GPT / fraction;
	}
	double result;
	int start = 0, end = n - 1;
	int tempK = partition(GPA, 0, n - 1, &result);
	while (tempK != k)
	{
		if (tempK < k)
		{
			start = tempK + 1;
			tempK = partition(GPA, start, end, &result);
		}
		else
		{
			end = tempK;
			tempK = partition(GPA, start, end, &result);
		}
	}
	cout << setiosflags(ios::fixed) << setprecision(2) << result << endl;
	delete[] GPA;
	return 0;
}
int partition(double data[], int start, int end, double *key)
{
	double pivotkey = data[start];
	*key = pivotkey;
	double temp;
	while (start < end)
	{
		while (start < end && data[end] < pivotkey)
			end--;
		temp = data[start];
		data[start] = data[end];
		data[end] = temp;
		while (start < end && data[start] >= pivotkey)
			start++;
		temp = data[start];
		data[start] = data[end];
		data[end] = temp;
	}
	return start;
}