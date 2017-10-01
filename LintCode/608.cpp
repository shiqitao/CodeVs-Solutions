class Solution {
public:
	/*
	* @param nums: an array of Integer
	* @param target: target = nums[index1] + nums[index2]
	* @return: [index1 + 1, index2 + 1] (index1 < index2)
	*/
	vector<int> twoSum(vector<int> &nums, int target) {
		// write your code here
		int size = nums.size();
		int left = 0;
		int right = size - 1;
		while (nums[left] + nums[right] != target)
		{
			if (nums[left] + nums[right] > target) right--;
			else left++;
		}
		vector<int> result(2);
		result[0] = left + 1;
		result[1] = right + 1;
		return result;
	}
};