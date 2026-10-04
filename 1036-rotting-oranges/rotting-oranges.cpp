class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        int m=grid.size();
        int n=grid[0].size();
        int cntFresh=0;

        vector<vector<int>> visited(m,vector<int>(n,0));
        queue<pair<pair<int,int>,int>> q;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){

                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    visited[i][j]=2;
                }
                if(grid[i][j]==1){
                    cntFresh++;
                }
            }
        }

        int min_time=0;
        int d_row[]={-1,1,0,0};
        int d_col[]={0,0,-1,1};

        while(!q.empty()){
           min_time=q.front().second;
           int row=q.front().first.first;
           int col=q.front().first.second;
           for(int i=0;i<4;i++){
               int t_row=row+d_row[i];
               int t_col=col+d_col[i];
              if(t_row<0 || t_row>=m || t_col<0 || t_col>=n){
                 continue;
              }
              if(visited[t_row][t_col]==2){
                continue;
              }
              if(grid[t_row][t_col]==1){
                visited[t_row][t_col]=2;
                q.push({{t_row,t_col},min_time+1});
                cntFresh--;
              }
           }
           q.pop();
        }

        if(cntFresh==0){
            return min_time;
        }
        return -1;
    }
};