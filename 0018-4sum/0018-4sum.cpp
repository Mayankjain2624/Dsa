class Solution {
    #define ll long long 
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
         ll n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for (ll i = 0; i < n-3; i++) {
            if (i > 0 && nums[i] == nums[i - 1])
             continue;
            for(ll j=i+1;j<n-2;j++){
                ll need = target-1LL*nums[j]-1LL*nums[i];
                if(j>(i+1) && nums[j]==nums[j-1])
                continue;
            ll l = j + 1;
            ll r = n - 1;
            while (l < r) {
            ll currentSum = nums[l] + nums[r];
                if (currentSum == need) {
                    ans.push_back({nums[i],nums[j], nums[l], nums[r]});
                    currentSum = 0;
                    ll prevL = l;
                    ll prevR = r;
                    while (nums[prevL] == nums[l] && l < r) {
                        prevL = l;
                        l++;
                    }
                    while (nums[prevR] == nums[r] && l<r) {
                        prevR = r;
                        r--;
                    }
                    // currentSum += (nums[l] + nums[r]);
                } else if (currentSum < need) {
                    // currentSum -= nums[l];
                    ll prevL = l;
                    while (nums[prevL] == nums[l] && l < n - 1) {
                        prevL = l;
                        l++;
                    }
                    // currentSum += nums[l];
                } else {
                    // currentSum -= nums[r];
                    ll prevR = r;
                    while (nums[prevR] == nums[r] && r > 0) {
                        prevR = r;
                        r--;
                    }
                    // currentSum += nums[r];
                }
            }
            }
        }
        return ans;
    }
};