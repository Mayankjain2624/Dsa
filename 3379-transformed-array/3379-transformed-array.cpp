class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n=nums.size();
        // vector<int>numsc=nums;
        vector<int>result(n);
        for(int i=0;i<n;i++){
            int x=0;
            if(nums[i]>0)
            x=(abs(nums[i])+i)%n;
            else if(nums[i]<0)
            x=(i-abs(nums[i])%n+n)%n;
            else
            x=i;
            result[i]=nums[x];
        }
        return result;
    }
};