#include <iostream>
#include <string>
using namespace std;
struct Steel
{
	int length;
	int diameter;
	int coding;
};
int main()
{
	int n; cin >> n;
	Steel *steel = new Steel[n];
	Steel maxSteel = { 0, 0, 0 };
	for (int i = 0; i < n; i++)
	{
		cin >> steel[i].length >> steel[i].diameter >> steel[i].coding;
		if (maxSteel.length < steel[i].length)
		{
			maxSteel.length = steel[i].length;
			maxSteel.diameter = steel[i].diameter;
			maxSteel.coding = steel[i].coding;
		}
		else if (maxSteel.length == steel[i].length && maxSteel.diameter> steel[i].diameter)
		{
			maxSteel.length = steel[i].length;
			maxSteel.diameter = steel[i].diameter;
			maxSteel.coding = steel[i].coding;
		}
		else if (maxSteel.length == steel[i].length && maxSteel.diameter == steel[i].diameter && maxSteel.coding < steel[i].coding)
		{
			maxSteel.length = steel[i].length;
			maxSteel.diameter = steel[i].diameter;
			maxSteel.coding = steel[i].coding;
		}
	}
	cout << maxSteel.coding << endl;
	return 0;
}