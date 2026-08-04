class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for(string c:tokens){

            if( (c=="+") || (c=="-") || (c=="*") || (c=="/")){

                int secOp=st.top();
                st.pop();

                int firsOp=st.top();
                st.pop();

                if(c=="+"){
                    st.push(firsOp+secOp);

                }
                if(c=="-"){
                    st.push(firsOp-secOp);
                    
                }
                if(c=="*"){
                    st.push(firsOp*secOp);
                    
                }
                if(c=="/"){
                    st.push(firsOp/secOp);
                    
                }

            }
            else{
                st.push(stoi(c));
            }
        }

        return st.top();
    }
};
