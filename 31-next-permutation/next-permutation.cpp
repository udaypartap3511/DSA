class Solution {
public:
    void nextPermutation(vector<int>& nums) {

        int n=nums.size();

        int index=n-2;
        while(index>=0){
           if(nums[index]<nums[index+1]){
            break;
           }
           index--;
        }

        if(index==-1){
            reverse(nums.begin(),nums.end());
            return;
        }
        
        for(int i=n-1;i>index;i--){
            if(nums[i]>nums[index]){
                swap(nums[i],nums[index]);
                break;
            }
        }

        reverse(nums.begin()+index+1,nums.end());
    }
};