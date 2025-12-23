class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        int n = events.size();
        sort(events.begin(), events.end(), [](const vector<int>&a, const vector<int>&b) {
            if(a[0]!=b[0]) return a[0]<b[0];
            return a[1]<b[1];
        });
        vector<int> mx(n);
        mx[n-1]=events[n-1][2];
        for(int i = n-2; i>=0; i--) {
        mx[i] = max(events[i][2], mx[i+1]);
        }
        vector<int> ends(n);
        int m=0;
        for(int i = 0; i < n; i++) ends[i] = events[i][0];
        for(int i = 0; i < n; i++) {
            int end1 = events[i][1];
            m = max(m, events[i][2]);
            int it = upper_bound(ends.begin(), ends.end(), end1) - ends.begin();
            if(it== n) continue;
            m=max(m, events[i][2]+mx[it]);
        }
        return m;
    }
};