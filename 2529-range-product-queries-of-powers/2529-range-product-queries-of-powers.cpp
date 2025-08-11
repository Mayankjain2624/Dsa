class Solution {
public:
    const int MOD = 1e9 + 7;

    long long modPow(long long base, long long exp) {
        long long res = 1;
        while (exp > 0) {
            if (exp & 1) res = (res * base) % MOD;
            base = (base * base) % MOD;
            exp >>= 1;
        }
        return res;
    }

    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        int p = log2(n);
        vector<int> powers;
        int i = -1;
        while (n > 0) {
            i++;
            int r = n % 2;
            if (r == 1)
                powers.push_back(1 << i);
            n = n / 2;
        }

        vector<long long> prefix(powers.size(), 1); 
        vector<int> ans;

        prefix[0] = powers[0] % MOD;
        for (int i = 1; i < powers.size(); i++)
            prefix[i] = (prefix[i - 1] % MOD * powers[i] % MOD) % MOD;

        for (auto& it : queries) {
            int l = it[0];
            int r = it[1];
            if (l == 0)
                ans.push_back(prefix[r] % MOD);
            else {
                long long inv = modPow(prefix[l - 1], MOD - 2);
                ans.push_back((prefix[r] * inv) % MOD);
            }
        }
        return ans;
    }
};
