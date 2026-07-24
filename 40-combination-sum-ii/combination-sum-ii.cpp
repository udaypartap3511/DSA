class Solution {
public:
   void solve(vector<int> &candidates,vector<vector<int>> &ans,vector<int> &v,int target,int i){
       if(target==0){
            ans.push_back(v);
            return;
        }

       for(int ind=i;ind<candidates.size();ind++){
          if(ind>i && candidates[ind]==candidates[ind-1]) continue;
 
          if(target<candidates[ind]) break;

            v.push_back(candidates[ind]);
            solve(candidates,ans,v,target-candidates[ind],ind+1);
            v.pop_back();
       }

     
   }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        vector<vector<int>> ans;
        sort(candidates.begin(),candidates.end());
        vector<int> v;
        solve(candidates,ans,v,target,0);
        
        return ans;
    }
};