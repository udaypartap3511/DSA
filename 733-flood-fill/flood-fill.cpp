class Solution {
public:
    void solve(vector<vector<int>>& image,int sr,int sc,int color,int s_col){
           
           if(sr<0 || sc<0 || sr>=image.size() || sc>=image[0].size()){
             return;
           }

           if(image[sr][sc]==color){
            return;
           }

           if(image[sr][sc]!=s_col){
            return;
           }

           if(image[sr][sc]==s_col){
            image[sr][sc]=color;
           }

           

           solve(image,sr+1,sc,color,s_col);
           solve(image,sr,sc-1,color,s_col);
           solve(image,sr,sc+1,color,s_col);
           solve(image,sr-1,sc,color,s_col);

    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        int s_col=image[sr][sc];

        solve(image,sr,sc,color,s_col);
        return image;
    }
};