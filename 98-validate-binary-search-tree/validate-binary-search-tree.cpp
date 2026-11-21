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
    bool solve(TreeNode* root,long long lb,long long ub){
        if(root==nullptr){
            return true;
        }

        if(root->val>=ub || root->val<=lb){
            return false;
        }

        return solve(root->left,lb,root->val)
                && solve(root->right,root->val,ub);
    }
    bool isValidBST(TreeNode* root) {
        
        return solve(root,LLONG_MIN,LLONG_MAX); 
    }
};