class Solution {
public:
    void lpsCompute(string needle,vector<int> &lps){

        int i=1;
        int len=0;
        lps[0]=0;

        while(i<needle.length()){
            if(needle[i]==needle[len]){
                len++;
                lps[i]=len;
                i++;
            }
            else{
                if(len!=0){
                    len=lps[len-1];
                }
                else{
                    lps[i]=0;
                    i++;
                }
            }
        }
        return;

    }
    int strStr(string haystack, string needle) {
        

       int n=needle.length();
       vector<int> lps(n);
       lpsCompute(needle,lps);
       int i=0;
       int j=0;

       while(i<haystack.length()){
          if(haystack[i]==needle[j]){
            i++;
            j++;
            if(j==n) return i-j;
          }
          else{
             if(j!=0){
                j=lps[j-1];
             }
             else{
                i++;
             }
          }
       }

       return -1;
    }
};