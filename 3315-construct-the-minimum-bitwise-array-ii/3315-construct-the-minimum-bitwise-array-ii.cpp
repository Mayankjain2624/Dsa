class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int i, n = nums.size();
        vector<int>ans(n);
        for(i = 0; i < n; i++) {
            int res = -1;
            for(int j = 0; j < 32; j++) {
                if(j == 0 && (nums[i] & (1 << j)) == 0) {
                    res = -1;
                    break;
                }
                else if((nums[i] & (1 << j)) == 0) {
                    res = nums[i] ^ (1 << (j - 1));
                    break;
                }
            }
            ans[i] = res;
        }
        return ans;
    }
};