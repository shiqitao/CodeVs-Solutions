class Solution {
public:
	/**
	* @param S, T: Two string.
	* @return: Count the number of distinct subsequences
	*/
	int numDistinct(string &S, string &T) {
		// write your code here
		int sLen = S.size();
		int tLen = T.size();
		if (tLen == 0) return 1;
		if (tLen > sLen) return 0;
		int *DP = new int[tLen];
		memset(DP, 0, sizeof(int)*tLen);
		for (int i = 0; i < sLen; i++) {
			for (int j = (i < tLen - 1 ? i : tLen - 1); j >= 0; j--) {
				if (S[i] == T[j]) {
					DP[j] += DP[j - 1];
				}
			}
			if (S[i] == T[0]) {
				DP[0] += 1;
			}
		}
		int result = DP[tLen - 1];
		delete[] DP;
		return result;
	}
};