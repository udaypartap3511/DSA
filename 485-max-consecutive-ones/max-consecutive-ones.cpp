class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {

        int cnt=0;
        int maxcnt=0;

        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                maxcnt=max(cnt,maxcnt);
                cnt=0;
            }
            else if(i==nums.size()-1){
                cnt++;
                maxcnt=max(cnt,maxcnt);
            }
            else{
                cnt++;
            }
        }

        return maxcnt;
        
    }
};