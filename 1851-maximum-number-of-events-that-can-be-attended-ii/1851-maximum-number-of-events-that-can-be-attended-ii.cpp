class Solution {
public:
    #define ll long long
    vector<vector<ll>> dp;

    // Recursive DP function
    ll solve(ll i, vector<vector<int>>& events, ll k) {
        if (i >= events.size()) return 0;
        if (k <= 0) return 0;
        if (dp[i][k] != -1LL) return dp[i][k];

        // Option 1: Skip the current event
        ll nt = solve(i + 1, events, k);

        // Option 2: Attend the current event and jump to the next non-overlapping event
        ll ind = upper_bound(events.begin() + i + 1, events.end(), events[i][1],
            [](ll val, const vector<int>& event) {
                return val < event[0]; // event[0] is the start time
            }) - events.begin();

        ll t = events[i][2] + solve(ind, events, k - 1); 

        return dp[i][k] = max(nt, t);
    }

    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(), events.end()); // Sort events by start time
        dp.resize(events.size() + 1, vector<ll>(k + 1, -1LL));
        return solve(0, events, k);
    }
};