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
		int sumProfit = 0;
		for (int i = 0; i < size - 1; i++) {
			if (prices[i] < prices[i + 1]) {
				sumProfit += prices[i + 1] - prices[i];
			}
		}
		return sumProfit;
	}
};