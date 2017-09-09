class Solution {
public:
	/*
	* @param A: An integer array
	* @return: An integer
	*/
	int singleNumber(vector<int> &A) {
		// write your code here
		int size = A.size();
		int result = 0;
		for (int i = 0; i < size; i++) {
			result ^= A[i];
		}
		return result;
	}
};