/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {

        if(node==nullptr){
            return nullptr;
        }
        
        queue<Node*> q;
        Node* root=new Node(node->val);
        unordered_map<Node*,Node*> mp;
        q.push(node);
        mp[node]=root;

        while(!q.empty()){

            Node* curr_node=q.front();
            Node* curr_mp=mp[q.front()];
            q.pop();

            for(Node* i:curr_node->neighbors){
                 
                 if(mp.find(i)==mp.end()){
                   
                   Node* new_node=new Node(i->val);
                   mp[i]=new_node;
                   q.push(i);
                 }
                 

                 curr_mp->neighbors.push_back(mp[i]);
            }
        }

        return root;

    }
};