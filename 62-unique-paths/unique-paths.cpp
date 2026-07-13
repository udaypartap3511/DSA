class Solution {
public:
    int ans(int m,int n,vector<vector<int>> &v,int i,int j){
        if(i>=m-1 || j>=n-1){
            return v[i][j]=1;
        }
        if(v[i][j]!=-1){
            return v[i][j];
        }

        return v[i][j]=ans(m,n,v,i+1,j)+ans(m,n,v,i,j+1);
    }
    int uniquePaths(int m, int n) {

        vector<vector<int>> v(m,vector<int>(n,-1));

        return ans(m,n,v,0,0);
        
    }
};