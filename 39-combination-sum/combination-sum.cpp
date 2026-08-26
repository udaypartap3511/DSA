class Solution {
public:
    void solve(vector<vector<int>> &ans,vector<int> &candidates,vector<int> &v,int target,int i){

        if(i==candidates.size()){
            if(target==0){
            ans.push_back(v);
            
        }
        return;
        }

        
        if(candidates[i]<=target){
             v.push_back(candidates[i]);
             solve(ans,candidates,v,target-candidates[i],i);
             v.pop_back();

        }
       
        solve(ans,candidates,v,target,i+1);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<vector<int>> ans;

        vector<int> v;

        solve(ans,candidates,v,target,0);

        return ans;
    }
};