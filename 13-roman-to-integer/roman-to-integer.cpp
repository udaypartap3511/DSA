class Solution {
public:
    int romanToInt(string s) {

        unordered_map<char,pair<int,int>> mp;
        mp['I']={1,0};
        mp['V']={5,1};
        mp['X']={10,2};
        mp['L']={50,3};
        mp['C']={100,4};
        mp['D']={500,5};
        mp['M']={1000,6};

        int n=s.length();
        int pre=n-1;
        int curr=n-1;
        int ans=0;
        while(curr>=0){
            if(curr==n-1){
               ans+=mp[s[curr]].first;
               curr--;
            }
            else{
                if(mp[s[curr]].second<mp[s[pre]].second){
                    ans-=mp[s[curr]].first;
                }
                else{
                   ans+=mp[s[curr]].first; 
                }
                curr--;
                pre--;
            }
        }

        return ans;
    }
};