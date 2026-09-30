class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {

        int n=heights.size();
        stack<int> st;
        int max_area=0;


        for(int i=0;i<n;i++){

            while(!st.empty()  && heights[st.top()]>=heights[i]){

                int element= st.top();
                st.pop();

                int width= st.empty()?i:i-st.top()-1;
                int area=heights[element]*width;
                max_area=max(max_area,area);
            }

            st.push(i);
        }

        while(!st.empty()){
             int element=st.top();
             st.pop();
             int width= st.empty()?n:n-st.top()-1;
             int area = heights[element]*width;
             max_area=max(max_area,area);
        }

        return max_area;
        
    }
};