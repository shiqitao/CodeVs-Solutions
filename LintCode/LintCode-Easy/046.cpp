class Solution {
public:
	/*
	* @param nums: a list of integers
	* @return: find a  majority number
	*/
	int majorityNumber(vector<int> &nums) {
		// write your code here
		int count = 1;
		int main = nums[0];
		int size = nums.size();
		for (int i = 1; i < size; i++) {
			if (nums[i] == main) {
				count++;
			}
			else {
				if (count == 0) {
					main = nums[i];
					count = 1;
				}
				else {
					count--;
				}
			}
		}
		return main;
	}
};