#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:	
	
public:
    
    TreeNode* robHouse(TreeNode* root){
    	if(root == NULL){
			root = robHouse(new TreeNode(0));
			return root;
		}
		if(root->left == NULL && root ->right == NULL){
			root->left = new TreeNode(0);
			root->right = new TreeNode(0);
			return root;
		}
    	root->left = robHouse(root->left);
    	root->right = robHouse(root->right);
		root->val = max(root->val + root->left->left->val + root->left->right->val + root->right->left->val + root->right->right->val,root->left->val + root->right->val);
		return root;
	}
	
    int rob(TreeNode* root) {
        return robHouse(root)->val;
    }
};
