class Solution {
public:
	/*
	* @param prices: Given an integer array
	* @return: Maximum profit
	*/
	int maxProfit(vector<int> &prices) {
		// write your code here
		int size = prices.size();
		if (size == 0 || size == 1) {
			return 0;
		}
		int min = prices[0];
		int max = prices[0];
		int maxProfit = 0;
		for (int i = 1; i < size; i++)
		{
			if (prices[i] > max) {
				max = prices[i];
				maxProfit = maxProfit>(max - min) ? maxProfit : (max - min);
			}
			else if (prices[i] < min) {
				min = prices[i];
				max = prices[i];
			}
		}
		return maxProfit;
	}
};