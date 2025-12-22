class Solution {
public:
    int find(vector<string>&str, int ind, int prev, vector<vector<int>>&dp){
        if(ind > str[0].size()) return 0;

        if(dp[ind][prev] != -1) return dp[ind][prev];

        int skip = find(str, ind+1, prev, dp);

        int take = 0;
        int pass = 1;

        if(prev != 0){
            for(int i = 0; i < str.size(); i++){
                if(str[i][ind-1] < str[i][prev-1]){
                    pass = 0;
                    break;
                }
            }
        }
        if(pass == 1){
            take = 1+ find(str, ind+1, ind, dp);
        }

        return dp[ind][prev] = max(skip, take);
    }


    int minDeletionSize(vector<string>& strs) {
        vector<vector<int>> dp(strs[0].size()+1, vector<int>(strs[0].size()+1, -1));
        return strs[0].size()-find(strs, 1, 0, dp);
        
    }
};