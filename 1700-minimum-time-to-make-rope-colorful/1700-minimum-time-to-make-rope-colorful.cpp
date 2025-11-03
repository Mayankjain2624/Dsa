class Solution {
public:
    // long long int dp(int i,char prev,string &colors,vector<int>&needed){
    //     if(i==0)
    //     {
    //         if(colors[i]==prev)
    //         return needed[0];
    //         else
    //         return 0;
    //     }
    //     if(colors[i]==prev)
    //     {
    //         return
    //         min(needed[i]+dp(i-1,prev,colors,needed),needed[i+1]+dp(i-1,colors[i],colors,needed));
    //     }
    //     else
    //     return dp(i-1,colors[i],colors,needed);
    // }
    int minCost(string colors, vector<int>& neededTime) {
        long long int n = colors.size();
        //    return dp(n-1,'#',colors,neededTime);
        long long int maxi=neededTime[0];
        long long int currSum=0;
        long long int totalSum=neededTime[0];
        for (long long int i = 1; i < n; i++) {
            totalSum+=neededTime[i];
              if(colors[i]==colors[i-1])
              {
                  maxi=max(maxi,neededTime[i]*1LL);
              }
              else
              {
                currSum+=maxi;
                maxi=neededTime[i];
              }
        }
        currSum+=maxi;
        // cout<<totalSum<<" "<<currSum<<endl;
        return totalSum-currSum;
    }
};