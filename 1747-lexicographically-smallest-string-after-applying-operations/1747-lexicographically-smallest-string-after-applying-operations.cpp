class Solution {
public:
    string findLexSmallestString(string s, int a, int b) {
        queue<string> q;
        q.push(s);
        unordered_set<string> seen;
        string ans = s;
        seen.insert(s);
        while (!q.empty()) {
            string st = q.front();
            string stc = st;
            q.pop();
            if (st < ans)
                ans = st;
            // option 1
            for (int i = 0; i < st.length(); i++) {
                if (i & 1) {
                    int ni = st[i] - '0';
                    ni = (ni + a) % 10;
                    st[i] = ni + '0';
                }
            }
            if (seen.count(st) == 0) {
                q.push(st);
                seen.insert(st);
            }
            // option 2
            string op2 =
                stc.substr(stc.length() - b) + stc.substr(0, stc.length() - b);
            if (seen.count(op2) == 0) {
                q.push(op2);
                seen.insert(op2);
            }
        }
        return ans;
    }
};