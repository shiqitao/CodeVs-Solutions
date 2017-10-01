/**
* Definition of TreeNode:
* class TreeNode {
* public:
*     int val;
*     TreeNode *left, *right;
*     TreeNode(int val) {
*         this->val = val;
*         this->left = this->right = NULL;
*     }
* }
*/


class Solution {
public:
	/*
	* @param root: A Tree
	* @return: Level order a list of lists of integer
	*/
	vector<vector<int>> levelOrder(TreeNode * root) {
		// write your code here
		vector<vector<int>> result;
		if (!root) {
			return result;
		}
		vector<TreeNode*> pre(1);
		pre[0] = root;
		vector<TreeNode*> next;
		vector<int> temp;
		while (pre.size()) {
			int size = pre.size();
			for (int i = 0; i < size; i++) {
				temp.push_back(pre[i]->val);
				if (pre[i]->left) {
					next.push_back(pre[i]->left);
				}
				if (pre[i]->right) {
					next.push_back(pre[i]->right);
				}
			}
			pre = next;
			next.clear();
			result.push_back(temp);
			temp.clear();
		}
		return result;
	}
};