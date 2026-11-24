/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {

        if (root==nullptr){
            return "";
        }

        queue<TreeNode*> q;
        q.push(root);
        string s="";

        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                TreeNode* curr_node= q.front();
                q.pop();
                if(curr_node==nullptr) s.append("#,");
                else{
                    s.append(to_string(curr_node->val)+',');
                    q.push(curr_node->left);
                    q.push(curr_node->right);
                }
            }
        }

        return s;
        
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        
        if(data.length()==0) return nullptr;

        stringstream s(data);
        string str;
        getline(s,str,',');
        TreeNode* root= new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){

            TreeNode* curr_node=q.front();
            q.pop();

            getline(s,str,',');

            if(str=="#"){
                curr_node->left=nullptr;
            }
            else{
                TreeNode* root=new TreeNode(stoi(str));
                curr_node->left=root;
                q.push(root);
            }

            getline(s,str,',');

            if(str=="#"){
                curr_node->right=nullptr;
            }
            else{
                TreeNode* root= new TreeNode(stoi(str));
                curr_node->right=root;
                q.push(root);
            }
        }

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));