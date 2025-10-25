class Solution {
public:
    void recursion(int n, string& curr, int open, int close,
                   vector<string>& ans) {
        if (open > n || close > n)
            return;
        if (open == n && close == n) {
            ans.push_back(curr);
            return;
        }
        if (open < close) {
            return;
        }
        curr += '(';
        recursion(n, curr, open + 1, close, ans);
        curr.pop_back();
        if(close<open){
            curr += ')';
            recursion(n, curr, open, close + 1, ans);
            curr.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string curr = "";
        recursion(n, curr, 0, 0, ans);
        return ans;
    }
};