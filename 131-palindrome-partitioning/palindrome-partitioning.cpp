class Solution {
public:
    bool isPalindrome(string s,int start,int end){
        while(start<=end){
            if(s[start++]!=s[end--]){
                return false;
            }
        }

        return true;
    }

    void solve(string s,vector<vector<string>> &ans,vector<string> &v,int i){
         if(i==s.length()){
            ans.push_back(v);
            return;
         }

         for(int ind=i;ind<s.length();ind++){
            if(isPalindrome(s,i,ind)){
               v.push_back(s.substr(i,ind-i+1));
               solve(s,ans,v,ind+1);
               v.pop_back();
            }
         }
    }
    vector<vector<string>> partition(string s) {

        vector<vector<string>> ans;

        vector<string> v;

        solve(s,ans,v,0);
        return ans;
        
    }
};