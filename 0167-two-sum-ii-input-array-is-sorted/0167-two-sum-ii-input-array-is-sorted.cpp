class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, r = n-1;
        while (l<r) {
            int cs = nums[l] + nums[r];
            if (cs == target) {
                break;
            }
            if (cs > target ) {
                r--;
            }
           else if (cs < target)
                l++;
        // cout << l << " " << r << endl;
        }
        vector<int> ans;
        ans.push_back(l + 1);
        ans.push_back(r + 1);
        return ans;
    }
};