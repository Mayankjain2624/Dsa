class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int n=startTime.size();
        vector<int>free(n+1);
        free[0]=startTime[0]-0;
        free[n]=eventTime-endTime[n-1];
        for(int i=1;i<n;i++){
           free[i]=startTime[i]-endTime[i-1];
        }
            int l=0;
            int r=min(k+1,n+1);
            int currentSum=0;
            for(int i=l;i<r;i++){
                currentSum+=free[i];
            }
            int maxi=currentSum;
            while(r<=n){
                currentSum-=free[l];
                currentSum+=free[r];
                maxi=max(maxi,currentSum);
                r++;
                l++;
            }
            return maxi;
    }
};