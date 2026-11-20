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
    bool solve(TreeNode* leftroot,TreeNode* rightroot){

        if(leftroot==nullptr || rightroot==nullptr){
            return (leftroot==rightroot);
        }

        if(leftroot->val!=rightroot->val){
            return false;
        }

           return
            solve(leftroot->left,rightroot->right)
                      &&
            solve(leftroot->right,rightroot->left);
        
    }
    bool isSymmetric(TreeNode* root) {
        
        if(root==nullptr) return true;

        return solve(root->left,root->right);

        
    }
};