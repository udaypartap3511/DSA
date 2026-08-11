class Solution {
public:
   void solve(vector<int> &nums,vector<vector<int>> &ans,int i){

    if(i==nums.size()){
        ans.push_back(nums);
        return;
    }

    for(int ind=i;ind<nums.size();ind++){
        swap(nums[i],nums[ind]);
        solve(nums,ans,i+1);
        swap(nums[i],nums[ind]);
    }
   }
    vector<vector<int>> permute(vector<int>& nums) {

       vector<vector<int>> ans;

       solve(nums,ans,0);

       return ans;
        
    }
};