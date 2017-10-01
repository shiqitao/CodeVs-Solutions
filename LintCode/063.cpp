class Solution {
public:
	/*
	* @param A: an integer ratated sorted array and duplicates are allowed
	* @param target: An integer
	* @return: a boolean
	*/
	bool search(vector<int> &A, int target) {
		// write your code here
		int size = A.size();
		if (size == 0) {
			return false;
		}
		int low = 0, high = size - 1, mid;
		if (A[low] == target || A[high] == target) {
			return true;
		}
		if (A[low] < target) {
			while (low + 1 < high) {
				mid = low + (high - low) / 2;
				if (A[mid] == target) {
					return true;
				}
				else if (A[mid] > target || A[mid] < A[0]) {
					high = mid;
				}
				else if (A[mid] > A[0]) {
					low = mid;
				}
				else {
					if (A[++low] == target) {
						return true;
					}
				}
			}
		}
		else {
			while (low + 1 < high) {
				mid = low + (high - low) / 2;
				if (A[mid] == target) {
					return true;
				}
				else if (A[mid] < target || A[mid] > A[0]) {
					low = mid;
				}
				else if (A[mid] < A[0]) {
					high = mid;
				}
				else {
					if (A[++low] == target) {
						return true;
					}
				}
			}
		}
		return false;
	}
};