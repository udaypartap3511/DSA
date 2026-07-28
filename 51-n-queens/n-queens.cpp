class Solution {
public: 
    bool isSafe(vector<string> &chess,int row,int col,int n){
        int duprow=row;
        int dupcol=col;
        while(row>=0 && col>=0){
            if(chess[row][col]=='Q') return false;
            row--;
            col--;
        }

        row=duprow;
        col=dupcol;

        while(row>=0 && col<n){
            if(chess[row][col]=='Q') return false;
            row--;
            col++;
        }

        row=duprow;
        col=dupcol;

        while(row>=0){
            if(chess[row][col]=='Q') return false;
            row--;
        }

        return true;
    }
    void solve(vector<vector<string>> &ans,vector<string> &chess,int row,int col,int n){
        if(row==n){
            ans.push_back(chess);
            return;
        }

        for(int col=0;col<n;col++){
            if(isSafe(chess,row,col,n)){
                chess[row][col]='Q';
                solve(ans,chess,row+1,col,n);
                chess[row][col]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> chess;
        string s(n,'.');
        for(int i=0;i<n;i++)
        {
            chess.push_back(s);
        }
        solve(ans,chess,0,0,n);

        return ans;
    }
};