class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int n=nums.size();
        if(n<=2)
            return n;
        int maxLen=1;

        vector<vector<int>> lis(n,vector<int>(k,1));
        int mod;
        for(int i=1;i<n;++i){
            for(int j=0;j<i;++j){
                mod = (nums[i]+nums[j])%k;
                if(1+lis[j][mod]>lis[i][mod])
                    lis[i][mod] = 1+lis[j][mod];
                maxLen = max(maxLen,lis[i][mod]);
            }
        }
        return maxLen;
    }
};