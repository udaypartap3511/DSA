class Solution {
public:

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        vector<int> res;

        for(int i:nums){
            mp[i]++;
        }

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

        for(auto &pair:mp){
            int first=pair.first;
            int second=pair.second;
            pq.push({second,first});
        }
        while(pq.size()>k){
            pq.pop();
        }
        while(!pq.empty()){
          res.push_back(pq.top().second);
          pq.pop();
        }

        return res;
    }
};