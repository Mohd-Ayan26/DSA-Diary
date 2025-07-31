//GFG
class Solution {
  public:
    // Function to merge k sorted arrays.
    class node
    {
        public:
        int row;
        int col;
        int data;
        
        node(int row,int col,int data)
        {
            this->row=row;
            this->col=col;
            this->data=data;
        }
    };
    
    class compare
    {
        public:
         
         bool operator()(node* a, node* b) {
                   return a->data > b->data;
         }
    };
    vector<int> mergeKArrays(vector<vector<int>> arr, int K) {
        // code here
        vector<int> ans;
        priority_queue<node*,vector<node*>,compare> pq;
        
        for(int i=0;i<K;i++)
        {
            pq.push(new node(i,0,arr[i][0]));
        }
        
        while(!pq.empty())
        {
            auto temp=pq.top();
            pq.pop();
            ans.push_back(temp->data);
            
            int row=temp->row;
            int col=temp->col;
            
            if(col+1<arr[row].size())
            {
                pq.push(new node(row,col+1,arr[row][col+1]));
            }
        }
        return ans;
    }
};
