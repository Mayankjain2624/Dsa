class Solution {
public:
    const int MOD = 1e9 + 7;

    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> powers;

        for (int i = 0; n > 0; i++) {
            if (n & 1) powers.push_back(1 << i);
            n >>= 1;
        }

        vector<int> ans;
        for (auto& it : queries) {
            int l = it[0];
            int r = it[1];
            long long prod = 1;
            for (int i = l; i <= r; i++) {
                prod = (prod * powers[i]) % MOD;
            }
            ans.push_back((int)prod);
        }
        return ans;
    }
};
