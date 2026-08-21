class Solution {
public:
    int partition_algo(int L,int R,vector<int> &nums){

        int P=nums[L];
        int i=L+1;
        int j=R;

        while(i<=j){
            if(nums[i]<P && nums[j]>P){
                swap(nums[i],nums[j]);
                i++;
                j--;
            }
            if(nums[i]>=P){
                i++;
            }
            if(nums[j]<=P){
                j--;
            }
        }

        swap(nums[j],nums[L]);

        return j;
    }
    int findKthLargest(vector<int>& nums, int k) {

     //hoare's partition
     int n=nums.size();
     int L=0;
     int R=n-1;
     
     int pivot_idx=0;
       
       while(true){

        pivot_idx=partition_algo(L,R,nums);

        if(pivot_idx==k-1){
            break;
        }
        if(pivot_idx>k-1){
            R=pivot_idx-1;
        }
        else{
            L=pivot_idx+1;
        }
       }
       
       return nums[pivot_idx];
    }
};