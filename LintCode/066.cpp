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
	* @return: Preorder in ArrayList which contains node values.
	*/
	vector<int> preorderTraversal(TreeNode * root) {
		// write your code here
		vector<int> result;
		if (root != NULL) {
			result.push_back(root->val);
			vector<int> temp = preorderTraversal(root->left);
			result.insert(result.end(), temp.begin(), temp.end());
			temp = preorderTraversal(root->right);
			result.insert(result.end(), temp.begin(), temp.end());
		}
		return result;
	}
};