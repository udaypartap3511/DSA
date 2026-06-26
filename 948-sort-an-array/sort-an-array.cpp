class Solution {
public:

   vector<int> merge(vector<int>&left,vector<int>&right){
    
    int i=0;
    int j=0;
    int m=left.size();
    int n=right.size();
    
    vector<int> res;

    while(i<m && j<n){
        if(left[i]<=right[j]){
            res.push_back(left[i++]);
        }
        else{
            res.push_back(right[j++]);
        }
    }

    while(i<m){
        res.push_back(left[i++]);
    }
    while(j<n){
        res.push_back(right[j++]);
    }

    return res;
   }

    vector<int> sortArray(vector<int>& nums) {
        if(nums.size()<=1){
            return nums;
        }
        int mid=nums.size()/2;

        vector<int> left(nums.begin(),nums.begin()+mid);
        vector<int> right(nums.begin()+mid,nums.end());

        left=sortArray(left);
        right=sortArray(right);

        return merge(left,right);


    }
};