class Solution {
public:
    int t[301];
    bool solve(int ind,unordered_set<string> & st,string s){
        int n=s.length();
        if(ind==n){
            return t[ind]=true;
        }
        if(t[ind]!=-1){
            return t[ind];
        }
        
        for(int len=1;len<=n;len++){
            string temp=s.substr(ind,len);
            if(st.find(temp)!=st.end() && solve(ind+len,st,s)){
                return t[ind]=true;
            }
        }

        return t[ind]=false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        
        memset(t,-1,sizeof(t));
        unordered_set<string> st;

        for(auto i:wordDict){
            st.insert(i);
        }

        if(solve(0,st,s))return true;

        return false;
    }
};