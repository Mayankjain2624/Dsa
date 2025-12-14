class Solution {
public:
int mod=1e9+7;
    int numberOfWays(string corridor) {
        int n=corridor.length();
        int ns=0;
        for(char c:corridor)
        {
            if(c=='S')
            ns++;
        }
        if(ns&1 || ns==0)
        return 0;
        vector<int>pos;
        int cnt=0;
        int last=-1;
        long long ans=1;
        for(int i=0;i<n;i++){
            if(corridor[i]=='S')
            {
              cnt++;
            if(cnt==3)
            {
                ans=(ans%mod*(i-last)%mod)%mod;
                cnt=1;
            }
            if(cnt==2)
            {
                last=i;
            }
            }
            // cout<<cnt<<endl;
        }
        for(int i:pos)
        cout<<i<<" ";
        return ans;
    }
};
