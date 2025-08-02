class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        unordered_map<int, int> mp;
        int min_ele = INT_MAX;

        for (int &x : basket1) {
            mp[x]++;
            min_ele = min(min_ele, x);
        }
        for (int &x : basket2) {
            mp[x]--;
            min_ele = min(min_ele, x);
        }

        vector<int> final;

        for (auto &it : mp) {
            int element = it.first;
            int diff = it.second;

            if (abs(diff) % 2 != 0) return -1;

            for (int i = 0; i < abs(diff) / 2; i++) {
                final.push_back(element);
            }
        }

        sort(final.begin(), final.end());

        long long result = 0;
        int n = final.size() / 2;

        for (int i = 0; i < n; i++) {
            result += min(final[i], 2 * min_ele);
        }

        return result;
    }
};