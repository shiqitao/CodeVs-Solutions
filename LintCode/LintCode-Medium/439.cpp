/**
* Definition of SegmentTreeNode:
* class SegmentTreeNode {
* public:
*     int start, end, max;
*     SegmentTreeNode *left, *right;
*     SegmentTreeNode(int start, int end, int max) {
*         this->start = start;
*         this->end = end;
*         this->max = max;
*         this->left = this->right = NULL;
*     }
* }
*/


class Solution {
public:
	/*
	* @param A: a list of integer
	* @return: The root of Segment Tree
	*/
	SegmentTreeNode * build(vector<int> &A) {
		// write your code here
		int size = A.size();
		if (size == 0) {
			return NULL;
		}
		return build(A, 0, size - 1);
	}
	SegmentTreeNode * build(vector<int> &A, int start, int end) {
		int max = A[start];
		for (int i = start + 1; i <= end; i++) {
			max = max > A[i] ? max : A[i];
		}
		SegmentTreeNode *root = new SegmentTreeNode(start, end, max);
		if (start == end) {
			root->left = NULL;
			root->right = NULL;
		}
		else {
			root->left = build(A, start, (start + end) / 2);
			root->right = build(A, (start + end) / 2 + 1, end);
		}
		return root;
	}
};