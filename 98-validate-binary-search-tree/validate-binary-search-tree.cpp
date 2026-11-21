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
    void solve(TreeNode* root,bool &flag,long long lb,long long ub){
        if(root==nullptr){
            return;
        }

        if(root->val>=ub || root->val<=lb){
            flag=false;
        }

        solve(root->left,flag,lb,root->val);
        solve(root->right,flag,root->val,ub);
    }
    bool isValidBST(TreeNode* root) {
        bool flag=true;
        solve(root,flag,LLONG_MIN,LLONG_MAX);
        return flag;  
    }
};