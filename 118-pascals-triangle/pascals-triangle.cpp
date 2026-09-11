class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        
        vector<vector<int>> ans;

        for(int row=1;row<=numRows;row++){
            vector<int> v;
            int res=1;
            v.push_back(res);
            for(int col=1;col<row;col++){
                res*=(row-col);
                res/=col;
                v.push_back(res);
            }
            ans.push_back(v);
        }

        return ans;
    }
};