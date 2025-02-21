//GFG solution
class Solution {
  public:
    vector <int> bottomView(Node *root) {
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
             mp[hd]=temp->data;
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
