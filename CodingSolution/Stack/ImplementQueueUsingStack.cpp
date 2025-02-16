class MyQueue {
public:
    stack<int> st;
    int solve(stack<int> &st,bool remove)
    {
         if(st.size()==1)
        {
            int element=st.top();
            if(remove)
                 st.pop();
            return element;
        }
        int num=st.top();
        st.pop();
        int bottomElement = solve(st,remove);
        st.push(num);
        return bottomElement;
        
    }
    
    MyQueue() {
        
    }
    
    void push(int x) {
        
        st.push(x);
    }
    
    int pop() {
        return solve(st,true);
      
    
    }
    
    int peek() {
     return solve(st,false);  
    }
    
    bool empty() {
        if(st.empty())
        {
            return true;
        }
        return false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
