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
	* @return: Postorder in ArrayList which contains node values.
	*/
	vector<int> postorderTraversal(TreeNode * root) {
		// write your code here
		vector<int> result;
		if (root != NULL) {
			vector<int> temp = postorderTraversal(root->left);
			result.insert(result.end(), temp.begin(), temp.end());
			temp = postorderTraversal(root->right);
			result.insert(result.end(), temp.begin(), temp.end());
			result.push_back(root->val);
		}
		return result;
	}
};