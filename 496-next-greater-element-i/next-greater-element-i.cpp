class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        vector<int> nge(nums1.size());
        unordered_map<int,int> nge2;
        stack<int> st;

        for(int i=nums2.size()-1;i>=0;i--){

            while(!st.empty() && st.top()<nums2[i]){
                st.pop();
            }

            if(st.empty()){
                nge2[nums2[i]]=-1;
            }
            else{
              nge2[nums2[i]]=st.top();
              
            }
            st.push(nums2[i]);
        }
        for(int i=0;i<nums1.size();i++){
            nge[i]=nge2[nums1[i]];
        }

        return nge;
    }
};