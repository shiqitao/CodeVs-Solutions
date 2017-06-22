#include <iostream>
#include <vector>
using namespace std;
struct Sale
{
	int price;
	int num;
	int profit;
};
bool ifMax(vector<Sale> &sale, int index, int tax);
bool ifMaxLeft(vector<Sale> &sale, int index, int tax);
bool ifMaxRight(vector<Sale> &sale, int index, int tax);
int main()
{
	int n; cin >> n;
	vector <Sale> sale;
	int price, num, profit;
	cin >> price >> num;
	int cost = price;
	int index;
	while (price != -1)
	{
		profit = (price - cost) * num;
		Sale temp = { price, num, profit };
		sale.push_back(temp);
		if (price == n)
			index = sale.size() - 1;
		cin >> price >> num;
	}
	int m; cin >> m;
	price = sale[sale.size() - 1].price;
	num = sale[sale.size() - 1].num;
	while (num > 0)
	{
		price += 1;
		num -= m;
		profit = (price - cost) * num;
		Sale temp = { price, num, profit };
		sale.push_back(temp);
		if (price == n)
			index = sale.size() - 1;
	}
	if (ifMax(sale, index, 0))
	{
		cout << 0 << endl;
		return 0;
	}
	bool stop1 = false, stop2 = false;
	int tax = 1;
	while (!stop1 || !stop2)
	{
		if (tax < n - cost && ifMaxRight(sale, index, -tax))
		{
			if (ifMaxLeft(sale, index, -tax))
			{
				cout << -tax << endl;
				return 0;
			}
		}
		else
			stop1 = true;
		if (ifMaxLeft(sale, index, tax))
		{
			if (ifMaxRight(sale, index, tax))
			{
				cout << tax << endl;
				return 0;
			}
		}
		else
			stop2 = true;
		tax++;
	}
	cout << "NO SOLUTION" << endl;
	return 0;
}
bool ifMax(vector<Sale> &sale, int index, int tax)
{
	for (int i = 0; i < sale.size(); i++)
	{
		if (sale[index].profit + tax * sale[index].num < sale[i].profit + tax * sale[i].num)
			return false;
	}
	return true;
}
bool ifMaxLeft(vector<Sale> &sale, int index, int tax)
{
	for (int i = 0; i < index; i++)
	{
		if (sale[index].profit + tax * sale[index].num < sale[i].profit + tax * sale[i].num)
			return false;
	}
	return true;
}
bool ifMaxRight(vector<Sale> &sale, int index, int tax)
{
	for (int i = index + 1; i < sale.size(); i++)
	{
		if (sale[index].profit + tax * sale[index].num < sale[i].profit + tax * sale[i].num)
			return false;
	}
	return true;
}