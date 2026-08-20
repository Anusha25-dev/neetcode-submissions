/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return funct2(root,INT_MIN,INT_MAX);
    }
    bool funct2(TreeNode* root, int min, int max){
        if(!root) return true;
        if(root->val<=min || root->val>=max) return false;
        return (funct2(root->left,min,root->val) && funct2(root->right,root->val,max));
    }
};
