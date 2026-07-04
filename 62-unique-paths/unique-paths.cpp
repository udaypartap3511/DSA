class Solution {
public:

    int answer(vector<vector<int>> &v,int i,int j,int m,int n){

        if(i==m-1 || j== n-1){
            return v[i][j]= 1;
        }

        else if(v[i][j]!=-1){
           return v[i][j];
        }

        return v[i][j]=answer(v,i+1,j,m,n)+answer(v,i,j+1,m,n);
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> v(m,vector<int>(n,-1));

        return answer(v,0,0,m,n);
    }
};