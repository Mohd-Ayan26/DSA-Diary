class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n=words.size();
        vector<int> state(words.size()); //each integer is the form of binary representation
        int ans=0;
        for(int i=0;i<n;i++)
        {
           for(auto ch:words[i])
           {
            state[i]|=1<<(ch-'a');      //to mark the position of each character as 1 in words[i]
           }

           for(int j=0;j<i;j++)
           {
            if(!(state[i] & state[j]))
            {
               //no common letter
               int len=(words[i].size()*words[j].size());
               ans=max(len,ans);
            }
           }
        }
        return ans;
    }
};
