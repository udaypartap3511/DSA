class StockSpanner {
public:
    
    stack<pair<int,int>> st;
    int idx;
    StockSpanner() {
        idx=0;
    }
    
    int next(int price) {
       idx++;
       while(!st.empty() && price>=st.top().first){
        st.pop();
       }

       int ans;
       if(st.empty()){
          ans=idx;
       }
       else{
          ans=idx-st.top().second;
       }

       st.push({price,idx});
       return ans;
       
        
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */