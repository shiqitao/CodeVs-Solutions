class Solution {
public:
	/*
	* @param A: an integer rotated sorted array
	* @param target: an integer to be searched
	* @return: an integer
	*/
	int search(vector<int> &A, int target) {
		// write your code here
		int size = A.size();
		if (size == 0) {
			return -1;
		}
		int low = 0, high = size - 1, mid;
		if (A[low] == target) {
			return low;
		}
		if (A[high] == target) {
			return high;
		}
		if (A[low] < target) {
			while (low + 1 < high) {
				mid = low + (high - low) / 2;
				if (A[mid] == target) {
					return mid;
				}
				else if (A[mid] > target || A[mid] < A[0]) {
					high = mid;
				}
				else {
					low = mid;
				}
			}
		}
		else {
			while (low + 1 < high) {
				mid = low + (high - low) / 2;
				if (A[mid] == target) {
					return mid;
				}
				else if (A[mid] < target || A[mid] > A[0]) {
					low = mid;
				}
				else {
					high = mid;
				}
			}
		}
		return -1;
	}
};