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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> v;
        queue<pair<TreeNode*,pair<int,int>>> q;
        map<int,map<int,multiset<int>>> mp;
        q.push({root,{0,0}});

        while(!q.empty()){
            auto it=q.front();
            q.pop();
            TreeNode* curr=it.first;
            int x=it.second.first;
            int y=it.second.second;
            mp[x][y].insert(curr->val);

            if(curr->left!=nullptr){
                q.push({curr->left,{x-1,y+1}});
            }
            if(curr->right!=nullptr){
                q.push({curr->right,{x+1,y+1}});
            }
        }

        for(auto i:mp){
            vector<int> temp;
            for(auto j:i.second){
              temp.insert(temp.end(),j.second.begin(),j.second.end());
            }
            
            v.push_back(temp);
        }

        return v;
    }
};