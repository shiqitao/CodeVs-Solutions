class Solution {
public:
	/**
	* @param nums a list of integer
	* @return void
	*/
	void wiggleSort(vector<int>& nums) {
		// Write your code here
		int size = nums.size();
		int temp;
		for (int i = 1; i < size; i++) {
			if (i % 2 && nums[i - 1]>nums[i]) {
				temp = nums[i - 1];
				nums[i - 1] = nums[i];
				nums[i] = temp;
			}
			else if (i % 2 == 0 && nums[i - 1] < nums[i]) {
				temp = nums[i - 1];
				nums[i - 1] = nums[i];
				nums[i] = temp;
			}
		}
	}
};