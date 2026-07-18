class Solution {
public:
    vector<vector<int>> generate(int numRows) {

        vector<vector<int>> v;

        for(int i=1;i<=numRows;i++){
            vector<int> ans;
            int res=1;
            ans.push_back(res);
            for(int j=1;j<i;j++){
                res*=(i-j);
                res/=j;
                ans.push_back(res);
            }
            v.push_back(ans);
        }
        return v;
    }
};