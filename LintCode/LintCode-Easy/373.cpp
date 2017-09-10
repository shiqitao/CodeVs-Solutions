class Solution {
public:
	/*
	* @param nums: an array of integers
	* @return: nothing
	*/
	void partitionArray(vector<int> &nums) {
		// write your code here
		int size = nums.size();
		int temp;
		for (int i = 0, j = size - 1; i < j; i++, j--)
		{
			while (i != j && nums[i] % 2) {
				i++;
			}
			while (i != j && nums[j] % 2 == 0) {
				j--;
			}
			temp = nums[i];
			nums[i] = nums[j];
			nums[j] = temp;
		}
	}
};