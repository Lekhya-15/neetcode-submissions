class Solution {
public:
    bool checkValidString(string s) {
        stack<int> st1;
        stack<int> st2;

        for(int i=0;i<s.size();i++){
            char c=s[i];
            if(c=='(') st1.push(i);
            else if(c=='*') st2.push(i);
            else{
                if(st1.empty() && st2.empty()) return false;
                else if(st1.empty()) st2.pop();
                else if(st2.empty()) st1.pop();
                else st1.pop();
            }
        }

        while(!st1.empty() && !st2.empty()){
            if(st1.top()>st2.top()) return false;
            st1.pop();
            st2.pop();
        }
        if(!st1.empty()) return false;
        return true;
    }
};
