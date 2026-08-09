class Solution {
public:
    int trap(vector<int>& height) {

        int n=height.size();

        int left=0;
        int right=n-1;
        int leftmost=0;
        int rightmost=0;
        int cnt=0;

        while(left<=right){

            if(leftmost<=rightmost){
                leftmost=max(leftmost,height[left]);
                cnt+=leftmost-height[left];
                left++;
            }
            else{
                rightmost=max(rightmost,height[right]);
                cnt+=rightmost-height[right];
                right--;
            }
        }
        
        return cnt;
    }
};