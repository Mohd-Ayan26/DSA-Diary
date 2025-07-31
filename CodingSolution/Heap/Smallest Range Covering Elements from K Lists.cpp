//Leetcode
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
    bool operator()(node* a,node*b)
    {
        return a->data>b->data;
    }
};
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<int> ans;
        priority_queue<node*,vector<node*>,compare> pq;
        int mini=INT_MAX;
        int maxi=INT_MIN;
        for(int i=0;i<nums.size();i++)
        {
            pq.push(new node(i,0,nums[i][0]));
            mini=min(mini,nums[i][0]);
            maxi=max(maxi,nums[i][0]);
        }
        int start=mini,end=maxi;
        while(!pq.empty())
        {
            auto temp=pq.top();
            pq.pop();

            mini=temp->data;
            if(maxi-mini<end-start)
            {
                start=mini;
                end=maxi;
            }
            int row=temp->row;
            int col=temp->col;
            if(col+1<nums[row].size())
            {
                maxi=max(maxi,nums[row][col+1]);
                pq.push(new node(row,col+1,nums[row][col+1]));
            }
            else 
            {
                break;
            }
        }
        return {start,end};

    }
};
