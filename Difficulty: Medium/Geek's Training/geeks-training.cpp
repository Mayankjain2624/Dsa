class Solution {
  public:
    int solve(vector<vector<int>>& arr,int day,int last,vector<vector<int>>& dp){
        if(day==0){
            int maxi=0;
            for(int task=0;task<3;task++){
                if(task!=last){
                    maxi=max(maxi,arr[0][task]);
                }
            }
            return maxi;
        }
        if(dp[day][last]!=-1)
        return dp[day][last];
        int maxi=0;
        for(int task=0;task<3;task++){
            if(task!=last){
                maxi=max(maxi,solve(arr,day-1,task,dp)+arr[day][task]);
            }
        }
        return dp[day][last]=maxi;
    }
    int maximumPoints(vector<vector<int>>& arr) {
        // Code here
        int n=arr.size();
     vector<vector<int>>dp(n,vector<int>(4,-1));
     return solve(arr,n-1,3,dp);
     
        
    }
};