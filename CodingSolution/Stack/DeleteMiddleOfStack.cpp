class Solution {
  private:
  void solve(int count,stack<int>&s,int n)
  {
      if(count==n/2)
      {
          s.pop();
          return;
      }
      int num=s.top();
      s.pop();
      solve(count+1,s,n);
      s.push(num);
  }
   
  public:
    // Function to delete middle element of a stack.
    void deleteMid(stack<int>& s) {
        int count=0;
        solve(count,s,s.size());
    }
};
