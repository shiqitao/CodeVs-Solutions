class Solution {
public:
	/*
	* @param heights: a vector of integers
	* @return: an integer
	*/
	int maxArea(vector<int> &heights) {
		// write your code here
		int size = heights.size();
		if (size == 0 || size == 1) {
			return 0;
		}
		int max = 0;
		int left, right, temp;
		for (int i = 0, j = size - 1; i < j;)
		{
			left = heights[i];
			right = heights[j];
			temp = (j - i)*(heights[i]>heights[j] ? heights[j] : heights[i]);
			max = max > temp ? max : temp;
			if (left > right) {
				j--;
			}
			else {
				i++;
			}
		}
		return max;
	}
};