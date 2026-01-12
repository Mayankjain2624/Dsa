class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int n=points.size();
        int ans=0;
        for(int i=0;i<n-1;i++){
            int x1=points[i][0];
            int y1=points[i][1];
            int x2=points[i+1][0];
            int y2=points[i+1][1];
                
                int dx=abs(x1-x2);
                int dy=abs(y1-y2);
                ans+=max(dx,dy);
        }
        return ans;
    }
};