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

class BSTiterator{
    private:
    stack<TreeNode*> st;
    bool reverse;
    public:

    BSTiterator(TreeNode* root,bool isReverse){
        reverse=isReverse;
        pushall(root);
    }
    void pushall(TreeNode* root){
        while(root!=nullptr){
            st.push(root);
            if(!reverse)root=root->left;
            else root=root->right;
        }
    }
    int next(){
        TreeNode* top=st.top();
        st.pop();
        if(!reverse) pushall(top->right);
        else pushall(top->left);
        return top->val;
    }
    
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        
        if(root==nullptr){
            return false;
        }

        BSTiterator l(root,false);
        BSTiterator r(root,true);

        int i=l.next();
        int j=r.next();

        while(i<j){
            if(i+j==k) return true;
            else if(i+j<k) i=l.next();
            else j=r.next();
        }

        return false;

    }
};