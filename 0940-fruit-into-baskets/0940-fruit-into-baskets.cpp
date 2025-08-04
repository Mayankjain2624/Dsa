class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> freq;
        int l = 0;
        int r = 0;
        int sz = fruits.size();
        int ans = 0;

        while (r < sz) {
            freq[fruits[r]]++;

            while (freq.size() > 2) {
                freq[fruits[l]]--;
                if (freq[fruits[l]] == 0) freq.erase(fruits[l]);
                l++;
            }
            ans = max(ans, r - l + 1);
            r++;
        }

        return ans;
    }
};