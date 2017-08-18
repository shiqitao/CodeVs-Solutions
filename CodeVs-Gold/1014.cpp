#include <iostream>
using namespace std;
#define MAX(x,y) (x>y?x:y)
#define MIN(x,y) (x<y?x:y)
int main()
{
	int v, n; cin >> v >> n;
	int *size = new int[n];
	for (int i = 0; i < n; i++)
		cin >> size[i];
	int *data = new int[n*(v + 1)];
	int temp = MIN(size[0], v + 1);
	for (int i = 0; i < temp; i++)
		data[i] = 0;
	for (int i = temp; i < v + 1; i++)
		data[i] = temp;
	for (int i = 1; i < n; i++)
	{
		temp = MIN(size[i], v + 1);
		for (int j = 0; j < temp; j++)
			data[i*(v + 1) + j] = data[(i - 1)*(v + 1) + j];
		for (int j = temp; j < v + 1; j++)
			data[i*(v + 1) + j] = MAX(data[(i - 1)*(v + 1) + j], data[(i - 1)*(v + 1) + j - temp] + temp);
	}
	cout << v - data[n*(v + 1) - 1] << endl;
	delete[] size;
	delete[] data;
	return 0;
}