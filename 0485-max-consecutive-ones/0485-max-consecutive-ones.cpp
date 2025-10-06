class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        int k=0;
        for(int i=0;i<n;i++){
            if(nums[i]==1)
            k++;
            else
            {
                ans=max(ans,k);
                k=0;
            }
        }
        return max(ans,k);
    }
};