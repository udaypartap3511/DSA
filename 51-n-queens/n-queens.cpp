class Solution {
public:
    bool isSafe(vector<string> &board,int row,int col,int n){

        int duprow=row;
        int dupcol=col;

        while(row>=0 && col>=0){
            if(board[row--][col--]=='Q') return false;
        }

        row=duprow;
        col=dupcol;

        while(row>=0 && col<n){
            if(board[row--][col++]=='Q') return false;
        }

        row=duprow;
        col=dupcol;

        while(row>=0){
            if(board[row--][col]=='Q') return false;
        }

        return true;
    }
    void solve(vector<vector<string>> & ans,vector<string> &board,int row,int n){

        if(row==n){
            ans.push_back(board);
            return;
        }

        for(int col=0;col<n;col++){
            if(isSafe(board,row,col,n)){
                board[row][col]='Q';
                solve(ans,board,row+1,n);
                board[row][col]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {

        vector<string> board;
        string s;
        for(int i=0;i<n;i++){
            s+='.';
        } 

        for(int i=0;i<n;i++){
            board.push_back(s);
        }
         
         vector<vector<string>> ans;
        solve(ans,board,0,n);
        
        return ans;
    }
};