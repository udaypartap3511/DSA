class Solution {
public:
   void solve(vector<vector<int>> &ans,vector<int> &nums,vector<int> &v,vector<bool> &used){
      
     if(v.size()==nums.size()){
        ans.push_back(v);
        return;
     }

     for(int i=0;i<nums.size();i++){
        if(used[i]) continue;

        used[i]=true;
        v.push_back(nums[i]);
        solve(ans,nums,v,used);
        v.pop_back();
        used[i]=false;


     }
   }
    vector<vector<int>> permute(vector<int>& nums) {
        
        vector<vector<int>> ans;

        vector<int> v;
        vector<bool> used(nums.size(),false);

        solve(ans,nums,v,used);

        return ans;
    }
};