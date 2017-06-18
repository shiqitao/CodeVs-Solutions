#include <iostream>
using namespace std;
int main()
{
	int depth1, depth2, depth3, depth4;
	cin >> depth1 >> depth2 >> depth3 >> depth4;
	if (depth1 < depth2 && depth2 < depth3 && depth3 < depth4)
		cout << "Fish Rising" << endl;
	else if (depth1 > depth2 && depth2 > depth3 && depth3 > depth4)
		cout << "Fish Diving" << endl;
	else if (depth1 == depth2 && depth2 == depth3 && depth3 == depth4)
		cout << "Fish At Constant Depth" << endl;
	else
		cout << "No Fish" << endl;
	return 0;
}