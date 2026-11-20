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
    void solve(TreeNode* leftroot,TreeNode* rightroot,bool &flag){

        if(leftroot==nullptr &&rightroot!=nullptr || leftroot!=nullptr && rightroot==nullptr){
            flag=false;
            return;
        }

        if(leftroot->val!=rightroot->val){
            flag=false;
            return;
        }

        if(leftroot->left){
            solve(leftroot->left,rightroot->right,flag);
        }
        if(leftroot->right){
            solve(leftroot->right,rightroot->left,flag);
        }
    }
    bool isSymmetric(TreeNode* root) {
        
        bool flag=true;

        solve(root,root,flag);
        return flag;
    }
};