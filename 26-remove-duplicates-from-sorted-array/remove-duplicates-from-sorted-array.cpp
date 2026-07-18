class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        set<int> st;

        for(int i=0;i<nums.size();i++){
            st.insert(nums[i]);
        }
        int left=0;
        for(int i:st){
            nums[left++]=i;
        }

        return left;
        
    }
};