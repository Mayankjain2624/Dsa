class Solution {
#define ll long long int
public:
    int beautySum(string s) {
        int n=s.length();
        ll ans=0;
        for(int i=0;i<n;i++){
            for(int j=i+2;j<n;j++){
                vector<int>freq(26,0);
                for(int k=i;k<=j;k++){
                       freq[s[k]-'a']++;
                }
                int mini=1e9;
                int maxi=1;
                for(int i:freq)
                {
                    if(mini>i && i>0)
                    mini=i;
                    if(maxi<i)
                    maxi=i;
                }
                ans+=(maxi-mini);
            }
        }
        return ans;
    }
};