class Solution {
public:
    int longestSubsequence(string s, int k) {
        int n = s.length();
        long long int cv = 0;
        for (int i = n - 1; i >= max(n - 32, 0); i--) {
            if (s[i] == '1')
                cv += pow(2, n - 1 - i);
        }
        cout << cv << endl;
        // return cv;
        int rc = 0;
        for (int i = 0; i < n - 32; i++) {
            if (s[i] == '1')
                rc++;
        }
        cout << rc << endl;
        int start = max(0, n - 32);
        for (int i = start; i < n; i++) {
            if (cv <= k)
                return n - rc;
            if (s[i] == '1') {
                cv -= (1LL << (n - i - 1));
                rc++;
            }
        }
        return n - rc;
    }
};