class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        sort(intervals.begin(),intervals.end());

        int n=intervals.size();

        vector<vector<int>> v;
        int i=0;

        while(i<n){
            int start=intervals[i][0];
            int end=intervals[i][1];
            while(i+1<n && intervals[i+1][0]<=end){
                end=max(end,intervals[i+1][1]);
                i++;
            }
            v.push_back({start,end});
            i++;
        }
        return v;
        
    }
};