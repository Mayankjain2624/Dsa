#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        int n = (int)s.size();
        int m = (int)t.size();
        if (m == 0 || n == 0 || n < m)
        return "";

        vector<int> need(128, 0), window(128, 0);
        for (char c : t) 
        need[(unsigned char)c]++;

        int match = 0;           
        int bestLen = INT_MAX;
        int bestL = 0;

        int l = 0, r = 0;
        while (r < n) {
            unsigned char rc = (unsigned char)s[r];
            window[rc]++;
            if (window[rc] <= need[rc]) match++;
            while (match >= m && l <= r) {
                int currLen = r - l + 1;
                if (currLen < bestLen) {
                    bestLen = currLen;
                    bestL = l;
                }
                unsigned char lc = (unsigned char)s[l];
                window[lc]--;
                if (window[lc] < need[lc]) match--;
                l++;
            }
            r++;
        }

        if (bestLen == INT_MAX) return "";
        return s.substr(bestL, bestLen);
    }
};
