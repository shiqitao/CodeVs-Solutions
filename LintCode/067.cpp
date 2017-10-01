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
	* @return: Inorder in ArrayList which contains node values.
	*/
	vector<int> inorderTraversal(TreeNode * root) {
		// write your code here
		vector<int> result;
		if (root != NULL) {
			vector<int> temp = inorderTraversal(root->left);
			result.insert(result.end(), temp.begin(), temp.end());
			result.push_back(root->val);
			temp = inorderTraversal(root->right);
			result.insert(result.end(), temp.begin(), temp.end());
		}
		return result;
	}
};