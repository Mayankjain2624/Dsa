class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        long long  n = prices.size();
        vector<long long > prefix(n), ws(n);
        ws[0] = prices[0] * strategy[0];
        prefix[0] = prices[0];
        for (long long  i = 1; i < n; i++) {
            prefix[i] = prices[i] + prefix[i - 1];
            ws[i] = ws[i - 1] + (prices[i] * strategy[i]);
        }
        long long  ans = max(prefix[k-1]-prefix[k/2-1]+ws[n-1]-ws[k-1],ws[n-1]);
        for (long long  i = 1; i < (n - k + 1); i++) {
            long long  half = i + k / 2;
            long long  last = i + k-1;
            long long  sum = prefix[last] - prefix[half - 1] + ws[i - 1] + ws[n - 1] -
                      ws[last];
            ans = max(ans, sum);
        }
        return ans;
    }
};