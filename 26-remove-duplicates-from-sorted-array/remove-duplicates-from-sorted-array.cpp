class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
    
    int i=0;
    int j=0;
    int n=nums.size();
    int cnt=1;
    while(j<n && i<n){
        while(j<n && nums[j]==nums[i]){
            j++;
        }
        if(j>=n){
            break;
        }
        nums[i+1]=nums[j];
        i++;
        cnt++;
    }
    return cnt;
    }
};