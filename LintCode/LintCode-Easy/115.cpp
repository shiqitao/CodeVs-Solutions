class Solution {
public:
	/*
	* @param obstacleGrid: A list of lists of integers
	* @return: An integer
	*/
	int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
		if (obstacleGrid[0][0]) {
			return 0;
		}
		else {
			obstacleGrid[0][0] = 1;
		}
		int m = obstacleGrid.size();
		int n = obstacleGrid[0].size();
		for (int i = 1; i < n; i++) {
			if (obstacleGrid[0][i]) {
				for (int j = i; j < n; j++) {
					obstacleGrid[0][j] = 0;
				}
				break;
			}
			else {
				obstacleGrid[0][i] = 1;
			}
		}
		for (int i = 1; i < m; i++) {
			if (obstacleGrid[i][0]) {
				for (int j = i; j < m; j++) {
					obstacleGrid[j][0] = 0;
				}
				break;
			}
			else {
				obstacleGrid[i][0] = 1;
			}
		}
		for (int i = 1; i < m; i++) {
			for (int j = 1; j < n; j++) {
				if (obstacleGrid[i][j]) {
					obstacleGrid[i][j] = 0;
				}
				else {
					obstacleGrid[i][j] = obstacleGrid[i - 1][j] + obstacleGrid[i][j - 1];
				}
			}
		}
		return obstacleGrid[m - 1][n - 1];
	}
};