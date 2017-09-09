class Solution {
public:
	/*
	* @param A: A string
	* @param B: A string
	* @return: The length of longest common subsequence of A and B
	*/
	int longestCommonSubsequence(string &A, string &B) {
		// write your code here
		int nA = A.size() + 1;
		int nB = B.size() + 1;
		if (nA == 1 || nB == 1) {
			return 0;
		}
		int *DP = new int[nA*nB];
		memset(DP, 0, sizeof(int)*nA*nB);
		for (int i = 1; i < nA; i++) {
			for (int j = 1; j < nB; j++) {
				if (A[i - 1] == B[j - 1]) {
					DP[i*nB + j] = DP[(i - 1)*nB + j - 1] + 1;
				}
				else {
					DP[i*nB + j] = DP[(i - 1)*nB + j]>DP[i*nB + j - 1] ? DP[(i - 1)*nB + j] : DP[i*nB + j - 1];
				}
			}
		}
		return DP[nA*nB - 1];
	}
};