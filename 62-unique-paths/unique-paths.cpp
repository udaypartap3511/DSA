class Solution {
public:
    int solve(vector<vector<int>> &mat,int i,int j,int m,int n){
        if(i==m-1 || j==n-1){
            return mat[i][j]=1;
        }

        if(mat[i][j]!=-1){
            return mat[i][j];
        }

        return mat[i][j]=solve(mat,i+1,j,m,n)+solve(mat,i,j+1,m,n);
    }
    int uniquePaths(int m, int n) {

        vector<vector<int>> mat(m,vector<int>(n,-1));
        
        return solve(mat,0,0,m,n);
    }
};