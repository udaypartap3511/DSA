class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {

        int cnt1=0;
        int cnt2=0;
        int ele1;
        int ele2;
        int n=nums.size();

        for(int i=0;i<nums.size();i++){
            if(cnt1==0 && ele2!=nums[i]){
                ele1=nums[i];
                cnt1++;
            }
            else if(cnt2==0 && ele1!=nums[i]){
                ele2=nums[i];
                cnt2++;
            }
            else if(nums[i]==ele1){
                cnt1++;
            }
            else if(nums[i]==ele2){
                cnt2++;
            }
            else{
                cnt1--;
                cnt2--;
            }
        }

        cnt1=0;
        cnt2=0;

        for(int i:nums){
            if(i==ele1) cnt1++;
            else if(i==ele2) cnt2++;
        }

        vector<int> v;

        if(cnt1>n/3){
           v.push_back(ele1);
        }
        if(cnt2>n/3){
           v.push_back(ele2);
        }

        return v;
        
    }
};