//gfg solution
class Solution
{
    public:
    
    // Function to reverse first k elements of a queue.
    queue<int> modifyQueue(queue<int> q, int k) {
        stack<int> st;
        for(int i=0;i<k;i++)
        {
            int elem=q.front();
            q.pop();
            st.push(elem);
        }
        for(int i=0;i<k;i++)
        {
            int elem=st.top();
            st.pop();
            q.push(elem);
        }
        int i=0;
        while(i!=q.size()-k)
        {
            int elem=q.front();
            q.pop();
            q.push(elem);
            i++;
        }
        return q;
    }
};
