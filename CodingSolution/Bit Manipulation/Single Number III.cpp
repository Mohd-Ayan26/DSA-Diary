class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long Xor=0;
        for(auto num:nums)
        {
            Xor^=num;
        }

        int mask=(Xor) & (-Xor);
        int groupA=0;
        int groupB=0;

        for(auto num:nums)
        {
            if(mask & num)
            {
                groupA^=num;
            }
            else
            {
                groupB^=num;
            }
        }

        return {groupA,groupB};
    }
};
