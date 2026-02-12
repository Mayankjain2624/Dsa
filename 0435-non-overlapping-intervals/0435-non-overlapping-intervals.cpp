class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b) {
        return a[1] < b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>&vp) {
        // vector<pair<int, int>> vp;
        // for (auto& it : intervals) {
        //     vp.push_back({it[0], it[1]});
        // }
        sort(vp.begin(), vp.end(), cmp);
        // for (auto& it : vp) {
        //     cout << it.first << " " << it.second << endl;
        // }
        int n = vp.size();
        int last = vp[0][1];
        int cnt = 1;
        for (int i = 1; i < n; i++) {
            if (vp[i][0] >= last) {
                cnt++;
                last = vp[i][1];
            }
            cout<<last<<endl;
        }

        return n-cnt;
    }
};