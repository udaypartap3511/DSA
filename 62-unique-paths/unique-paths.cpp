class Solution {
public:
    int dpcount(vector<vector<int>>& v,int i, int j){
         if(i==v.size()-1 && j==v[0].size()-1){
            return 1;
         }
          if(i>v.size()-1 || j>v[0].size()-1){
            return 0;
         }

         if(v[i][j]!=-1){
            return v[i][j];
         }

         return v[i][j]= dpcount(v,i+1,j)+dpcount(v,i,j+1);
    }
    int uniquePaths(int m, int n) {

       //use memoization

        vector<vector<int>> v(m,vector<int>(n,-1));

        return dpcount(v,0,0);
        
    }
};