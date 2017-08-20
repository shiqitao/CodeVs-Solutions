#include <iostream>
#include <string>
using namespace std;
void converse(const string order, const string posterior);
int main()
{
	string order, posterior;
	cin >> order >> posterior;
	converse(order, posterior);
	return 0;
}
void converse(const string order, const string posterior)
{
	int length = order.length();
	if (length == 0) return;
	if (length == 1)
	{
		cout << order;
		return;
	}
	cout << posterior[length - 1];
	int num = order.find(posterior[length - 1]);
	string order_left, order_right, posterior_left, posterior_right;
	order_left.assign(order, 0, num);
	order_right.assign(order, num + 1, length - num - 1);
	posterior_left.assign(posterior, 0, num);
	posterior_right.assign(posterior, num, length - num - 1);
	converse(order_left, posterior_left);
	converse(order_right, posterior_right);
}