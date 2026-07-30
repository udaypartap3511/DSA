class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        unordered_map<char,int> mp;
        int i=0;
        int j=0;
        int maxlen=0;
        while(j<s.length()){
            if(mp.find(s[j])!=mp.end() && i<=mp[s[j]]){
                i=mp[s[j]]+1;
            }
            maxlen=max(maxlen,j-i+1);
            mp[s[j]]=j;
            j++;
        }

        return maxlen;
        
    }
};