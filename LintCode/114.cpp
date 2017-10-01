class Solution {
public:
	/*
	* @param m: positive integer (1 <= m <= 100)
	* @param n: positive integer (1 <= n <= 100)
	* @return: An integer
	*/
	int uniquePaths(int m, int n) {
		// write your code here
		int temp = n > m ? m : n;
		n += m - 2;
		m = temp - 1;
		long long result = 1;
		for (int i = 0; i < m; i++) {
			result *= (n - i);
			result /= i + 1;
		}
		return result;
	}
};