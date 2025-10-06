class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int l = -1, r = -1;
        int len = nums.size();
        for (int i = 1; i < len; i++) {
            if (nums[i] > nums[i - 1])
                r = i - 1;
        }
        if (r != -1) {
            int k = -1;
            for (int i = r + 1; i < len; i++) {
                if (nums[i] > nums[r])
                    k = i;
            }
            swap(nums[r], nums[k]);
        }
        reverse(nums.begin() + r + 1, nums.end());
    }
};