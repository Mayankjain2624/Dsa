class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int n=nums.size();
        long long x=0;
        vector<bool>ans(n);
        for(int i=0;i<n;i++){
             x=x<<1;
             x=x+nums[i];
             if(x%5)
             ans[i]=false;
             else
             ans[i]=true;
             x=x%5;
        }
        return ans;
    }
};