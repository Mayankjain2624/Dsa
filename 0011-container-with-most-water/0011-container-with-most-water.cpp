class Solution {
public:
    int maxArea(vector<int>& height) {
        int l=0,r=height.size()-1;
        vector<int>ans;
        while(l<r){
            // int wh=min(height[l],height[r]);
            if(height[l]<height[r])
            {
             ans.push_back(height[l]*(r-l));
                l++;
            }
            else
            {
                ans.push_back(height[r]*(r-l));
                r--;
            }
        }
        return *max_element(ans.begin(),ans.end());
    }
};