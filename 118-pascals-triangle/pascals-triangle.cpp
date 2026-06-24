class Solution {
public:



vector<vector<int>> generate(int numRows) {
    
    vector<vector<int>> v;
   
   for(int row=1;row<=numRows;row++)
   {
      vector<int> eachr;
      int res=1;
      eachr.push_back(res);
      for(int col=1;col<row;col++){
        res*=row-col;
        res/=col;
        eachr.push_back(res);
      }
      v.push_back(eachr);
   }

   return v;

    }
};