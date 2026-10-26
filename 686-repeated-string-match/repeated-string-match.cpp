class Solution {
public:
  
   void lpsCompute(string b,vector<int> &lps){
     
     int i=1;
     int len=0;
     lps[0]=0;

     while(i<b.length()){

        if(b[i]==b[len]){
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
   bool kmp(string a,string b){
      
      int n=b.length();
      vector<int> lps(n);

      lpsCompute(b,lps);

      int i=0;
      int j=0;
      while(i<a.length()){

        if(a[i]==b[j]){
            i++;
            j++;
            if(j==b.length()) return true;
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
      return false;
   }
    int repeatedStringMatch(string a, string b) {
        
        int a_len=a.length();
        int b_len=b.length();

        int n=b_len/a_len;
        int cnt=n;
        string na="";

        while(cnt--){
            na+=a;
        }

        if(kmp(na,b)){
            return n;
        }

        na+=a;
        if(kmp(na,b)){
            return n+1;
        }
        
        na+=a;
        if(kmp(na,b)){
            return n+2;
        }

        return -1;
    }
};