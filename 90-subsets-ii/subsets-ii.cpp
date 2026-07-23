class Solution {
public:
    void solve(vector<int> & nums,set<vector<int>> &ans,vector<int> &v,int i){
        if(i==nums.size()){
            ans.insert(v);
            return;
        }
        v.push_back(nums[i]);
        solve(nums,ans,v,i+1);
        v.pop_back();
        solve(nums,ans,v,i+1);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        set<vector<int>> ans;
        sort(nums.begin(),nums.end());
        
        vector<int> v;
        solve(nums,ans,v,0);

        vector<vector<int>> res;
        for(auto i:ans){
            res.push_back(i);
        }
        

        return res;
        
    }
};