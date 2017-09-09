class Solution {
public:
	/**
	* @param A : An integer array
	* @return : An integer
	*/
	int singleNumberII(vector<int> &A) {
		// write your code here
		int size = A.size();
		int bit;
		int result = 0;
		for (int i = 0; i < 32; i++)
		{
			bit = 0;
			for (int j = 0; j < size; j++)
			{
				if ((A[j] & 1) == 1) {
					bit++;
				}
				A[j] >>= 1;
			}
			bit %= 3;
			result |= bit << i;
		}
		return result;
	}
};