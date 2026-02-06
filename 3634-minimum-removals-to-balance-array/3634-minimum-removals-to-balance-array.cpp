class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int mb=0;
        int j=0;
        for(int i=0;i<n;i++){
            while(nums[i]>(long long)nums[j]*k)
                j++;
            mb=max(mb,i-j+1);
        }
        return n-mb;
    }
};