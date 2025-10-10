class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n=intervals.size();
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>combined;
        int startLast=intervals[0][0];
        int endLast=intervals[0][1];
        for(int i=1;i<n;i++){
            if(intervals[i][0]<=endLast)
            {
                endLast=max(intervals[i][1],endLast);
            }
            else
            {
                  combined.push_back({startLast,endLast});
                  startLast=intervals[i][0];
                  endLast=intervals[i][1];
            }
        }
        combined.push_back({startLast,endLast});
        return combined;
    }
};