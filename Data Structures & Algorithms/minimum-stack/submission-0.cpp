class MinStack {
private:
stack<int> st;
stack<int> ex;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        int mini = !ex.empty() ? min(ex.top(),val) : val;
        ex.push(mini);
    }
    
    void pop() {
        st.pop();
        ex.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return ex.top();
    }
};
