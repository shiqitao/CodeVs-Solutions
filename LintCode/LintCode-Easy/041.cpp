class Solution {
public:
	/**
	* @param nums: A list of integers
	* @return: A integer indicate the sum of max subarray
	*/
	int maxSubArray(vector<int> nums) {
		if (nums.size() == 0) return 0;
		int max = nums[0];
		int sum = max;
		for (int i = 1; i < nums.size(); i++) {
			if (max < 0) {
				max = max >= nums[i] ? max : nums[i];
				sum = max;
			}
			else {
				sum += nums[i];
				if (sum < 0) sum = 0;
				max = sum>max ? sum : max;
			}
		}
		return max;
	}
};