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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {

        map<int,int> inmap;

        for(int i=0;i<inorder.size();i++){
            inmap[inorder[i]]=i;
        }

        TreeNode* root= treebuild(postorder,postorder.size()-1,0,inorder,0,inorder.size()-1,inmap);

        return root;
        
    }

    TreeNode* treebuild(vector<int> &postorder,int poststart,int postend,vector<int> &inorder,int instart,int inend,map<int,int> &inmap){

        if(poststart<postend || instart>inend) return nullptr;
          
          TreeNode* root= new TreeNode(postorder[poststart]);

          int inroot= inmap[root->val];
          int numsright= inend-inroot;

          root->right = treebuild(postorder,poststart-1,poststart-numsright,inorder,inroot+1,inend,inmap);

          root->left = treebuild(postorder,poststart-numsright-1,postend,inorder,instart,inroot-1,inmap);

          return root;
    }
};