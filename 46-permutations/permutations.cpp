class Solution {
public:
void solve(vector<int> &nums,vector<vector<int>> &ans,vector<bool> &used,vector<int> &curr){
        if(curr.size()==nums.size()){
        ans.push_back(curr);
        return;
        }

        for(int i=0;i<nums.size();i++){
          if(used[i]) continue;

          used[i]=true;
          curr.push_back(nums[i]);
          solve(nums,ans,used,curr);
          curr.pop_back();
          used[i]=false;
        }
}
    vector<vector<int>> permute(vector<int>& nums) {

        vector<vector<int>> ans;
        vector<bool> used(nums.size(),false);
        vector<int> curr;

        solve(nums,ans,used,curr);

        return ans;
        
    }
};