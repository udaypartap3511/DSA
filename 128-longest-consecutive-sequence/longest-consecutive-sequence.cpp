class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int cnt=1;
        int maxcnt=1;
        if(nums.empty()){
            return 0;
        }
        for(int i=0;i<nums.size();i++){
            if(i>0 && nums[i]==nums[i-1]+1){
                cnt++;
            }
            else if(i>0 && nums[i]==nums[i-1]){
                continue;
            }
            else{
                cnt=1;
            }
            maxcnt=max(cnt,maxcnt);
        }
        return maxcnt;
    }
};