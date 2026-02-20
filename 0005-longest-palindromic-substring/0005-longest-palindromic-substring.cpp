class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        int maxLen = 0;
        int maxStart = 0;
        for (int i = 0; i < n; i++) {
            int l = i - 1;
            int r = i + 1;
            int currLen = 1;
            while (l >= 0 && r < n) {
                if (s[l] == s[r]) {
                    currLen += 2;
                    l--;
                    r++;
                } else
                    break;
            }
            if (currLen > maxLen) {
                maxLen = currLen;
                maxStart = l + 1;
            }
            if (i + 1 < n && s[i] == s[i + 1]) {
                l = i - 1;
                r = i + 2;
                currLen=2;
                while (l >= 0 && r < n) {
                    if (s[l] == s[r]) {
                        currLen += 2;
                        l--;
                        r++;
                    } else
                        break;
                }
                if (currLen > maxLen) {
                    maxLen = currLen;
                    maxStart = l + 1;
                }
            }
        }
        string ans = s.substr(maxStart, maxLen);
        return ans;
    }
};
