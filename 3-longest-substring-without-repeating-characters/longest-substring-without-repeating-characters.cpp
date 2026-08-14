class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        unordered_map<int,int> mp;
        int i=0;
        int j=0;
        int maxcnt=0;

        while(j<s.length()){
            if(mp.find(s[j])!=mp.end() && i<=mp[s[j]]){
                i=mp[s[j]]+1;
            }
            mp[s[j]]=j;
            maxcnt=max(maxcnt,j-i+1);
            j++;
        }

        return maxcnt;
    }
};