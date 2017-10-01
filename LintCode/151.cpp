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
		vector<int> left(size, 0);
		vector<int> right(size, 0);
		int min = prices[0];
		int max = prices[0];
		left[0] = 0;
		for (int i = 1; i < size; i++) {
			if (prices[i] > max) {
				max = prices[i];
			}
			left[i] = (max - min) > left[i - 1] ? (max - min) : left[i - 1];
			if (prices[i] < min) {
				min = prices[i];
				max = prices[i];
			}
		}
		min = prices[size - 1];
		max = prices[size - 1];
		right[size - 1] = 0;
		for (int i = size - 2; i >= 0; i--) {
			if (prices[i] < min) {
				min = prices[i];
			}
			right[i] = (max - min) > right[i + 1] ? (max - min) : right[i + 1];
			if (prices[i] > max) {
				min = prices[i];
				max = prices[i];
			}
		}
		int maxProfit = 0;
		for (int i = 0; i < size; i++) {
			maxProfit = maxProfit>(left[i] + right[i]) ? maxProfit : (left[i] + right[i]);
		}
		return maxProfit;
	}
};