class Solution {
public:
void solve(vector<int> &nums,vector<vector<int>> &ans,int i,vector<int> &v,vector<bool> &used){

    if(v.size()==nums.size()){
        ans.push_back(v);
        return;
    }

    for(int ind=0;ind<nums.size();ind++){
        if(used[ind]) continue;
        v.push_back(nums[ind]);
        used[ind]=true;
        solve(nums,ans,ind+1,v,used);
        v.pop_back();
        used[ind]=false;
    }
   }
    vector<vector<int>> permute(vector<int>& nums) {

       vector<vector<int>> ans;
       vector<int> v;
       vector<bool> used(nums.size(),false);

       solve(nums,ans,0,v,used);

       return ans;
        
    }
};