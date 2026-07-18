class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int left=0;
        int right=0;
        int cnt=0;
        unordered_map<char,int> mp;
        while(right<s.length()){
            if(mp.find(s[right])!=mp.end() && left<=mp[s[right]]){
                left=mp[s[right]]+1;
            }
            mp[s[right]]=right;
            cnt=max(cnt,right-left+1);
            right++;
        }
        return cnt;
    }
};