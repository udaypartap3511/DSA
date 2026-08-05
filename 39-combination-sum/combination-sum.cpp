class Solution {
public:
void solve(vector<int> &candidates,vector<vector<int>> &ans,vector<int> &v,int target,int i){
    if(target==0){
        ans.push_back(v);
        return;
    }

    for(int ind=i;ind<candidates.size();ind++){
        if(ind>i && candidates[ind]==candidates[ind-1]) continue;

        if(candidates[ind]<=target){
            v.push_back(candidates[ind]);
            solve(candidates,ans,v,target-candidates[ind],ind);
            v.pop_back();
        }
    }

     
}
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

        vector<vector<int>> ans;
        vector<int> v;
        sort(candidates.begin(),candidates.end());

        solve(candidates,ans,v,target,0);

        return ans;
        
    }
};