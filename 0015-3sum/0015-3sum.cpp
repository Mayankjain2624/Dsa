class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for (int i = 0; i < n-2; i++) {
            int need = -nums[i];
            if (i > 0 && nums[i] == nums[i - 1])
             continue;
            int l = i + 1;
            int r = n - 1;
            int currentSum = nums[l] + nums[r];
            while (l < r) {
                if (currentSum == need) {
                    ans.push_back({nums[i], nums[l], nums[r]});
                    currentSum = 0;
                    int prevL = l;
                    int prevR = r;
                    while (nums[prevL] == nums[l] && l < r) {
                        prevL = l;
                        l++;
                    }
                    while (nums[prevR] == nums[r] && l<r) {
                        prevR = r;
                        r--;
                    }
                    currentSum += (nums[l] + nums[r]);
                } else if (currentSum < need) {
                    currentSum -= nums[l];
                    int prevL = l;
                    while (nums[prevL] == nums[l] && l < n - 1) {
                        prevL = l;
                        l++;
                    }
                    currentSum += nums[l];
                } else {
                    currentSum -= nums[r];
                    int prevR = r;
                    while (nums[prevR] == nums[r] && r > 0) {
                        prevR = r;
                        r--;
                    }
                    currentSum += nums[r];
                }
            }
        }
        return ans;
    }
};
// -4 -1 -1 0 1 2