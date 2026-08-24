/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;x(0, dfs(root->left));$0
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
int sum=INT_MIN;
        int dfs(TreeNode* root){
            if(!root) return 0;
            int l=max(0,dfs(root->left));
            int r=max(0,dfs(root->right));
            sum=max(sum,root->val+l+r);
            return root->val+max(l,r); //to extend a path through this root, which direction is the best
        }
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return sum;
    }
};
