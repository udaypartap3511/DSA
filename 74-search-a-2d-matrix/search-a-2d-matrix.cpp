class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int row;

        int i=0;
      
       while(i<matrix.size()){
         if(target>=matrix[i][0] && target<=matrix[i][matrix[0].size()-1]){
            row=i;
            break;
         }
         else{
            i++;
         }
       }

       if(i>=matrix.size()){
        return false;
       }

       int low=0;
       int high=matrix[0].size()-1;
       while(low<=high){
        int mid=(low+high)/2;
        if(target<matrix[row][mid]){
            high=mid-1;
        }
        else if(target>matrix[row][mid]){
            low=mid+1;
        }
        else{
            return true;
        }
       }

       return false;
        
    }
};