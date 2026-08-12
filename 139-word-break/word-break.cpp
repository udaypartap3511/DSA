class Solution {
public:
     int t[301];
    bool solve(int ind,string s,unordered_set<string> &mp){

        int n=s.length();
        if(ind==n){
            return t[ind]= true;
        }
        if(t[ind]!=-1){
            return t[ind];
        }
        // if(mp.find(s)!=mp.end()){
        //     return t[ind]=true;
        // }

        for(int l=1;l<=n;l++){
            string temp=s.substr(ind,l);
            if(mp.find(temp)!=mp.end() && solve(ind+l,s,mp)){
               return t[ind]=true;
            }
        }

        return t[ind]=false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {

        unordered_set<string> mp;
        memset(t,-1,sizeof(t));

        for(auto i:wordDict){
            mp.insert(i);
        }

        if(solve(0,s,mp)==true) return true;

        return false;
        
    }
};