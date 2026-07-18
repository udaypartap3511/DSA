class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        if(nums.empty()){
            return 0;
        }

        unordered_set<int> st;

        for(int i=0;i<nums.size();i++){
            st.insert(nums[i]);
        }

        int maxcnt=1;

        for(int i:st){
            if(st.find(i-1)==st.end()){
                int cnt=1;
                int x=i;
                while(st.find(x+1)!=st.end()){
                    cnt++;
                    x=x+1;
                }
                maxcnt=max(cnt,maxcnt);
            }
        }
        return maxcnt;
    }
};