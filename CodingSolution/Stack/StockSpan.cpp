class StockSpanner {
public:
   //create the stack having pair of price and span 
    stack<pair<int,int>> st;
    StockSpanner() {
        
    }
    
    int next(int price) {
        if(st.empty())
        {
            st.push({price,1});
            return 1;
        }
        else
        {
            int val=1;
            if(price>=st.top().first)
            {
                while(!st.empty() && price>=st.top().first)
                {
                    val=val+st.top().second;
                    st.pop();
                }
            }
            st.push({price,val});
            return val;
        }

    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
