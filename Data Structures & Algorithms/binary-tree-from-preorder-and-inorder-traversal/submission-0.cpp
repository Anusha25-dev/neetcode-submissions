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
    unordered_map<int,int> inorderindex;
    int preorderPos=0; //preorder decides root everytime we have left,right and root sub-system - main root=preorder[0]
    TreeNode* build(vector<int>& preorder, vector<int>& inorder,int left,int right){
        if(left>right) return nullptr; //inorder array done
        int rootval=preorder[preorderPos++];
        TreeNode* root=new TreeNode(rootval);

        int index=inorderindex[rootval];
        root->left=build(preorder,inorder,left,index-1);
        root->right=build(preorder,inorder,index+1,right);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i=0;i<inorder.size();i++){
            inorderindex[inorder[i]]=i; //saving index(in inorder) of all elemnets 
        }
        return build(preorder,inorder,0,inorder.size()-1);
    }
};
