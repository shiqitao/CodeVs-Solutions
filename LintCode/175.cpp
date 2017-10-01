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
	/**
	* @param root: a TreeNode, the root of the binary tree
	* @return: nothing
	*/
	void invertBinaryTree(TreeNode *root) {
		// write your code here
		if (root->left != NULL) {
			if (root->right == NULL) {
				root->right = root->left;
				root->left = NULL;
				invertBinaryTree(root->right);
			}
			else {
				TreeNode *temp = root->right;
				root->right = root->left;
				root->left = temp;
				invertBinaryTree(root->left);
				invertBinaryTree(root->right);
			}
		}
		else if (root->right != NULL) {
			root->left = root->right;
			root->right = NULL;
			invertBinaryTree(root->left);
		}
	}
};