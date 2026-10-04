class Solution {
public:
    int partition_algo(int left,int right,vector<int> &nums){
        
        int p=left;
        int i=left+1;
        int j=right;

        while(i<=j){

           if(nums[i]<nums[p] && nums[j]>nums[p]){
            swap(nums[i],nums[j]);
            i++;
            j--;
           }
           if(nums[i]>=nums[p]){
            i++;
           }
           if(nums[j]<=nums[p]){
            j--;
           }
        }

        swap(nums[left],nums[j]);

        return j;
    }
    int findKthLargest(vector<int>& nums, int k) {
        
        int n=nums.size();
        int left=0;
        int right=n-1;
        int pvt_idx=0;

        while(true){

            pvt_idx=partition_algo(left,right,nums);

            if(pvt_idx==k-1){
                break;
            }
            if(pvt_idx>k-1){
                right=pvt_idx-1;
            }
            else{
                left=pvt_idx+1;
            }
        }

        return nums[pvt_idx];
    }
};