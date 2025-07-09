class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int n=startTime.size();
        vector<int>free;
        free.push_back(startTime[0]);
        for(int i=1;i<n;i++){
           free.push_back(startTime[i]-endTime[i-1]);
        }
        free.push_back(eventTime-endTime[n-1]);
            int l=0;
            int r=min(k+1,n+1);
            int currentSum=0;
            for(int i=l;i<r;i++){
                currentSum+=free[i];
            }
            int maxi=currentSum;
            while(r<=n){
                currentSum+=(free[r++]-free[l++]);
                maxi=max(maxi,currentSum);
            }
            return maxi;
    }
};