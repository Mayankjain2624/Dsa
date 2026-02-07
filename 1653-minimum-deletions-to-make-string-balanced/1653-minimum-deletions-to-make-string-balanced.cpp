class Solution {
public:
    int minimumDeletions(string s) {
        int n=s.length();
        vector<int>nb(n,0),na(n,0);
        int bc=0;
        for(int i=0;i<n;i++){
             nb[i]=bc;
             if(s[i]=='b')
             bc++;
        }
           int ac=0;
        for(int i=n-1;i>=0;i--)
        {
           na[i]=ac;
           if(s[i]=='a')
           ac++;
        }
        // for(int i:nb)
        // cout<<i<<" ";
        // cout<<endl;
        // for(int i:na)
        // cout<<i<<" ";
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
           ans=min(ans,na[i]+nb[i]);
        }
        return ans;
    }
};