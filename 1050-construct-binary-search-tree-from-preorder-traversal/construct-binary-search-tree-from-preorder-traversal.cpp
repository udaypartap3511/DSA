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
    TreeNode* treebuilder(vector<int> &preorder,int &pos,int ub){
        
        if(pos==preorder.size() || preorder[pos]>ub){
            return nullptr;
        }

        TreeNode* root=new TreeNode(preorder[pos++]);

           
            root->left= treebuilder(preorder,pos,root->val);
            root->right= treebuilder(preorder,pos,ub);
        
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int pos=0;
        return treebuilder(preorder,pos,INT_MAX);
    }
};