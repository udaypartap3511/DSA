class Solution {
public:

    bool dfs(vector<vector<int>> &adj,vector<bool> &vis,int node,vector<bool> &pathvis){
       
       vis[node]=true;
       pathvis[node]=true;

       for(int i:adj[node]){

        if(!vis[i]){
            if(dfs(adj,vis,i,pathvis)==false) return false;
        }
        else if(pathvis[i]){
            return false;
        }
       }
       pathvis[node]=false;
       return true;
       
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<vector<int>> adj(numCourses+1);
        
        for(auto i:prerequisites){
            int u=i[0];
            int v=i[1];

            adj[u].push_back(v);
        }

        vector<bool> vis(numCourses+1,false);
        vector<bool> pathvis(numCourses+1,false);

        for(int i=0;i<numCourses;i++){

            if(!vis[i]){
                if(dfs(adj,vis,i,pathvis)==false) return false;
            }
        }
        
        return true;
    }
};