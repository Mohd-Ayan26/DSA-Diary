//GFG solution
/*struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/
class Solution {
  public:
    // Function to return a list of nodes visible from the top view
    // from left to right in Binary Tree.
    vector<int> topView(Node *root) {
         vector<int> ans;
         map<int,int> mp;
         queue<pair<Node*,int>> q;
         q.push({root,0});
         while(!q.empty())
         {
             pair<Node*,int> p=q.front();
             q.pop();
             Node* temp=p.first;
             int hd=p.second;
             if(mp.find(hd)==mp.end())
             {
                 mp[hd]=temp->data;
             }
             if(temp->left)
             {
                 q.push({temp->left,hd-1});
             }
             if(temp->right)
             {
                 q.push({temp->right,hd+1});
             }
         }
         for(auto i:mp)
         {
             ans.push_back(i.second);
         }
         return ans;
    }
};
