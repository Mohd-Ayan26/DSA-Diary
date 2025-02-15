class MinStack {
public:
    stack<long long int> st;
    long long int minval;
    MinStack() {
        
    }
    
    void push(int val) {
        if(st.empty())
        {
            st.push(val);
            minval=val;
        }
        else if(val<minval)
        {
            st.push((long long int)2*val-minval);
            minval=val;
        }
        else
        {
            st.push(val);
        }
        
    }
    
    void pop() {
        if(st.top()<minval)
        {
            minval=(long long int )(2*minval-st.top());
        }
        st.pop();
    }
    
    int top() {
        if(st.top()<minval)
        {
            return minval;
        }
        else
        {
            return st.top();
        }
    }
    
    int getMin() {
        return minval;
    }
};
