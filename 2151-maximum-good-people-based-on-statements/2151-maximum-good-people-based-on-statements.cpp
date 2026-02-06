class Solution {
public:

    int maximumGood(vector<vector<int>>& statements) {
        int n = statements.size();
        int nc = 1 << n;
            int maxi=0;
        for (int mask = 0; mask < nc; mask++) {
            int flag=1;
            int gp=0;
            for(int i=0;i<n;i++){
                if(mask&(1<<i)){
                    gp++;
                    for(int j=0;j<n;j++){
                        if(statements[i][j]==1){
                            if((mask&(1<<j))==0)
                            flag=0;
                        }
                        if(statements[i][j]==0){
                            if(mask &(1<<j))
                            flag=0;
                        }
                    }
                }
            }
            if(flag)
            {
            maxi=max(maxi,gp);
            }
        }
        return maxi;
    }
};