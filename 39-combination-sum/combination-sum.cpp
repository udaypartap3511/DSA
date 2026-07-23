class Solution {
public:
    void solve(vector<int> &candidates,vector<vector<int>> &ans,vector<int> &v,int target,int i){
        
        if(i==candidates.size()){
            if(target==0){
                ans.push_back(v);
            }
            return;
        }
        

        if(target>=candidates[i]){
            v.push_back(candidates[i]);
           solve(candidates,ans,v,target-candidates[i],i);
           v.pop_back();
        }

        solve(candidates,ans,v,target,i+1);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

        vector<vector<int>> ans;
        vector<int> v;
        sort(candidates.begin(),candidates.end());
        solve(candidates,ans,v,target,0);
        
        return ans;
        
    }
};