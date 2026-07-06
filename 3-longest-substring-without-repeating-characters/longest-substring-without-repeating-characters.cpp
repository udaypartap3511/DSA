class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int i=0;
        int j=0;
        int len=0;
        int maxlen=0;
        unordered_map<char,int> mp;

        while(j<s.length()){
           if(mp.find(s[j])!=mp.end()){
             if(mp[s[j]]>=i){
                i=mp[s[j]]+1;
             }
           }
           len=j-i+1;
           maxlen=max(maxlen,len);
           mp[s[j]]=j;
           j++;
        }

        return maxlen;
        
    }
};