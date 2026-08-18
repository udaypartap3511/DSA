class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        
        int n=nums.size();
        int low=1;
        int high=nums.size()-2;

        if(nums.size()>1 && nums[0]!=nums[1]){
            return nums[0];
        }
         if(nums.size()>1 && nums[n-1]!=nums[n-2]){
            return nums[n-1];
        }

        if(nums.size()==1){
            return nums[0];
        }

        int ele;

        while(low<=high){

            int mid=(low+high)/2;

            if(nums[mid]!=nums[mid+1] && nums[mid]!=nums[mid-1]){
                return nums[mid];
            }
            else if(nums[mid]==nums[mid^1]){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }

        return -1;
    }
};