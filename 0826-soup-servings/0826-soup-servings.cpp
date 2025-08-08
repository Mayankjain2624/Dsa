class Solution {
public:
    double soupServings(int n) {
        if (n > 4451)
            return 1.0;
        n = (n + 24) / 25;
        unordered_map<int, double> dp;
        return check(n, n, dp);
    }

    double check(int a, int b, unordered_map<int, double>& dp) {
        if (a <= 0 && b <= 0)
            return 0.5;
        if (a <= 0)
            return 1.0;
        if (b <= 0)
            return 0.0;
        int key = a * 5000 + b;
        if (dp.count(key))
            return dp[key];
        dp[key] = 0.25 * (check(a - 4, b, dp) + check(a - 3, b - 1, dp) + check(a - 2, b - 2, dp) + check(a - 1, b - 3, dp));
        return dp[key];
    }
};