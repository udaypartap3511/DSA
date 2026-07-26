class Solution {
public:
    void solve(vector<int> &nums,vector<vector<int>> &ans,vector<int> &v,int i){
      
      ans.push_back(v);

      for(int ind=i;ind<nums.size();ind++){
        if(ind>i && nums[ind]==nums[ind-1]) continue;

        v.push_back(nums[ind]);
        solve(nums,ans,v,ind+1);
        v.pop_back();
      }

    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        vector<vector<int>> ans;
        vector<int> v;
        sort(nums.begin(),nums.end());

        solve(nums,ans,v,0);

        return ans;
        
    }
};