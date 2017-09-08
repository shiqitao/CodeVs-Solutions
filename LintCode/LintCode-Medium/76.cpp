class Solution {
public:
	/**
	* @param nums: The integer array
	* @return: The length of LIS (longest increasing subsequence)
	*/
	int longestIncreasingSubsequence(vector<int> nums) {
		// write your code here
		int n = nums.size();
		if (n == 0) {
			return 0;
		}
		int *DP = new int[n];
		int MAX = 0;
		memset(DP, 0, sizeof(int)*n);
		for (int i = 1; i < n; i++) {
			for (int j = 0; j < i; j++) {
				if (nums[i]>nums[j] && DP[i] < DP[j] + 1) {
					DP[i] = DP[j] + 1;
				}
			}
			MAX = DP[i]>MAX ? DP[i] : MAX;
		}
		delete[] DP;
		return MAX + 1;
	}
};