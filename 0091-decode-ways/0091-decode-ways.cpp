class Solution {
public:
    set<string> st;
    int solve(string& s, int i, vector<int>& dp) {
        if (i == s.length()) {
           return 1;
        }
        if(s[i]==0)
        return 0;
        if (dp[i] != -1)
            return dp[i];
        int ones = s[i] - '0';
        int ways=0;
        if (ones >= 1 && ones <= 9) {
            // char ch = 'a' + (ones - 1);
            // string ns = currS + ch;
            ways+=solve(s,i+1,dp);
            // solve(s, ns, i + 1, dp);
        }
        if (i + 1 < s.length()) {
            int tens = s[i] - '0';
            int ones2 = s[i + 1] - '0';
            int num = tens * 10 + ones2;
            if (num >= 1 && num <= 26 && tens != 0) {
                // char ch = 'a' + num - 1;
                // string ns = currS + ch;
                ways+=solve(s,i+2,dp);
            }
        }

        return dp[i]=ways;
    }
    int numDecodings(string s) {
        int n = s.length();
        vector<int> dp(n, -1);
        // string ns = "";
        return solve(s, 0, dp);
        // for(auto &it:s)
        // cout<<it<<" ";
        // cout << endl;
        // return 
    }
};
