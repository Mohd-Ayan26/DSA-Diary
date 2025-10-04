//leetcode
class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int i=0,j=n-1;
        int max_area=INT_MIN;

        while(i<j)
        {
            
            if(height[i]<=height[j])
            {
               max_area=max(max_area,height[i]*(j-i));
               i++;
            }
            else
            {
                max_area=max(max_area,height[j]*(j-i));
                j--;
            }
            
        }
        return max_area;
    }
};
