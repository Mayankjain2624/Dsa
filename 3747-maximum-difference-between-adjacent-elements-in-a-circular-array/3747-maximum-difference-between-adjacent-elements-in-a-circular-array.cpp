class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int maxi=0;
        for(int i=0;i<nums.size();i++){
            maxi=max(maxi,abs(nums[i]-nums[(i+1)%nums.size()]));
        }
        return maxi;
    }
};