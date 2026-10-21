class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;
        string p="";

        for(char i:s){

            if(i!=' '){
                p+=i;
            }
            else if(!p.empty()){
                st.push(p);
                p.clear();
            }
        }

        if(!p.empty()){
            st.push(p);
            p.clear();
        }

        while(st.size()!=1){
            p+=st.top();
            p+=' ';
            st.pop();
        }

        p+=st.top();
        return p;
        
    }
};