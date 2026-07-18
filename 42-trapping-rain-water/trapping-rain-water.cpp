class Solution {
public:
    int trap(vector<int>& height) {

        int n=height.size();
        int left=0;
        int right=n-1;
        int leftmax=height[left];
        int rightmax=height[right];
        int cnt=0;

        while(left<=right){
            if(leftmax<=rightmax){
                leftmax=max(leftmax,height[left]);
                cnt+=leftmax-height[left];
                left++;

            }
            else{
                rightmax=max(rightmax,height[right]);
                cnt+=rightmax-height[right];
                right--;
            }
        }

        return cnt;

        
    }
};