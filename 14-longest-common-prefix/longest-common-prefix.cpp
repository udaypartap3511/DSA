class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        sort(strs.begin(),strs.end());
        string ans="";
      

         for(int j=0;j<strs[0].length();j++){
           for(int i=1;i<strs.size();i++){
              if(strs[i][j]!=strs[i-1][j]) return ans;
           }
            ans+=strs[0][j];

        }
       
       return ans;
        
    }
};