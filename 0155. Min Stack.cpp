class MinStack {
public:
    stack<int> st;
    int min = -1;
    MinStack() {
        
    }
    
    void push(int val) {
        // if the val is a new min, then push (1) the prev min (2) push the new min 
        if (st.empty()){
            min = val;
            st.push(val);
        }
        else if (min >= val){
            st.push(min);
            min = val;
        }
        st.push(val);
    }
    
    void pop() {
        if (st.top() == getMin()){
            st.pop();
            min = st.top(); 
        }
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return min;
    }
};

// Runtime 24 ms Beats 90.82% 
// Memory 16.4 MB Beats 70.71%
