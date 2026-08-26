class Solution {
public:
    bool isPalindrome(string s){
        int i=0;
        int j=s.length()-1;
        while(i<=j){
            if(s[i]!=s[j]){
                return false;
            }
            i++;
            j--;
        }

        return true;
    }
    void solve(string s,vector<vector<string>> &ans,vector<string> &v,int i){
        
        if(i==s.length()){
            ans.push_back(v);
            return;
        }

        for(int ind=i;ind<s.length();ind++){

            if(isPalindrome(s.substr(i,ind-i+1))){
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