class Solution {
public:
#define ll long long int
    int shipWithinDays(vector<int>& weights, int days) {
        ll l = *max_element(weights.begin(),weights.end());
        ll r = 0;
        ll ans = 0;
        for (int i : weights)
            r += i;
        while (l <= r) {
            ll mid = l + (r - l) / 2;
            ll rd = 1;
            int cs = 0;
            for (int i : weights) {
                cs += i;
                if (cs > mid) {
                    rd++;
                    cs = i;
                }
            }
            if (rd <= days) {
                ans = mid;
                r = mid - 1;
            } else
                l = mid + 1;
        }
        return ans;
    }
};