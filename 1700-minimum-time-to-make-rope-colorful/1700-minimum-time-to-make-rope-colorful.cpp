class Solution {
public:
    long long int dp(int i,int prev,string &colors,vector<int>&needed,vector<int>&dpv){
        if(i<0)
        {
            return 0;
            // if(colors[i]==colors[prev])
            // return needed[0];
            // else
            // return 0;
        }
        if(dpv[i]!=-1)
        return dpv[i];
        int x=0;
        if(colors[i]==colors[prev])
        {
            if(needed[i]>=needed[prev])
            x= needed[prev]+dp(i-1,i,colors,needed,dpv);
            else
            x= needed[i]+dp(i-1,prev,colors,needed,dpv);
        }
        else
        x=dp(i-1,i,colors,needed,dpv);
        return dpv[i]=x;
    }
    int minCost(string colors, vector<int>& neededTime) {
        long long int n = colors.size();
        vector<int>dpv(n,-1);
           return dp(n-2,n-1,colors,neededTime,dpv);
        // long long int maxi=neededTime[0];
        // long long int currSum=0;
        // long long int totalSum=neededTime[0];
        // for (long long int i = 1; i < n; i++) {
        //     totalSum+=neededTime[i];
        //       if(colors[i]==colors[i-1])
        //       {
        //           maxi=max(maxi,neededTime[i]*1LL);
        //       }
        //       else
        //       {
        //         currSum+=maxi;
        //         maxi=neededTime[i];
        //       }
        // }
        // currSum+=maxi;
        // // cout<<totalSum<<" "<<currSum<<endl;
        // return totalSum-currSum;
    }
};