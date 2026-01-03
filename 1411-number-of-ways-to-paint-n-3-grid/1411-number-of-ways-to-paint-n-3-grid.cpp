class Solution {
public:
    vector<vector<int>> dp;
    vector<string> states={
        "RGB","RGR","RBG","RBR",
        "GBR","GRB","GRG","GBG",
        "BGR","BRG","BRB","BGB"
    };
    int mod=1e9+7;
    bool valid(int i,int j){
        for(int t=0;t<3;t++){
            if(states[i][t]==states[j][t]) return false;
        }
        return true;
    }
    int solve(int n,int prevState){
        if(n==0) return 1;
        if(dp[n][prevState]!=-1) return dp[n][prevState];
        int cnt=0;
        for(int currState=0;currState<12;currState++){
            if(prevState==currState){
                continue;
            }
            if(valid(prevState,currState)==false){
                continue;
            }
            cnt=(cnt+solve(n-1,currState)%mod)%mod;
        }
        return dp[n][prevState]=cnt%mod;
    }
    int numOfWays(int n) {
        int cnt=0;
        dp.resize(n,vector<int>(12,-1));
        for(int i=0;i<12;i++){
            cnt=(cnt+solve(n-1,i)%mod)%mod;
        }
        return cnt;
    }
};