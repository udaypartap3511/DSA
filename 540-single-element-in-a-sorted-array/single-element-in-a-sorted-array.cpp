class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {

        int cnt=0;

        for(int i=0;i<nums.size();i++){
            cnt^=nums[i];
        }

        return cnt;
        
    }
};