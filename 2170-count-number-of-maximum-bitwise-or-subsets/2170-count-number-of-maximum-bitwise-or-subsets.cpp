class Solution {
public:
    int maxp = 0;
    int f(vector<int>& nums, int i, int x) {
        if (i == nums.size())
        {
            if(x==maxp)
            return 1;
            else
            return 0;
        }
           int pick = f(nums, i + 1, x | nums[i]);
           int notpick = f(nums, i + 1, x);
        return pick + notpick;
    }
    int countMaxOrSubsets(vector<int>& nums) {
        for (int i : nums) {
            maxp = maxp | i;
        }
        cout<<maxp<<endl;
        return f(nums, 0, 0);
    }
};