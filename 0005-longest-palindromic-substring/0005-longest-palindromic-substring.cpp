class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int maxi = 0;
        pair<int, int> ans;
        for (int i = 0; i < n; i++) {
            int mid = i;
            int l = i;
            int r = i;
            while (l >= 0 && r < n && s[l] == s[r]) {
                if (r - l + 1 > maxi) {
                    maxi = r - l + 1;
                    ans = {l, r};
                }
                l--, r++;
            }
            l = i, r = i + 1;
            while (l >= 0 && r < n && s[l] == s[r]) {
                if (r - l + 1 > maxi) {
                    maxi = r - l + 1;
                    ans = {l, r};
                }
                l--, r++;
            }
        }
        cout << maxi << endl;
        string as = s.substr(ans.first, ans.second - ans.first + 1);
        return as;
    }
};