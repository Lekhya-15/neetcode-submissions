class Solution {
public:
    bool isop(string s){
        return s=="+" || s=="-" || s=="/" || s=="*";
    }
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int i=0;

        while(i<tokens.size()){
            if(isop(tokens[i])){
                int top1=st.top();
                st.pop();
                int top2;
                if(st.size()){
                    top2=st.top();
                    st.pop();
                    if(tokens[i]=="+") st.push(top1+top2);
                    if(tokens[i]=="-") st.push(top2-top1);
                    if(tokens[i]=="/") st.push(top2/top1);
                    if(tokens[i]=="*") st.push(top1*top2);
                }
                else{
                    if(tokens[i]=="-") st.push(top1*-1);
                }

            }
            else{
                st.push(stoi(tokens[i]));
            }
            i++;
        }

        return st.top();
    }
};
