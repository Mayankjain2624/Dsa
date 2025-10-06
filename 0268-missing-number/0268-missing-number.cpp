class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int t=nums.size(),c=0;
        for(int i=0;i<n;i++){
        c^=nums[i];
        t^=i;
        }
        return t^c;
    }
};