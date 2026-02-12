class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0,r=0;
        int n=s.length();
        map<int,int>mp;
        int ans=0;
        while(r<n){
             mp[s[r]]++;
             while(mp[s[r]]>1 && l<r){
                 mp[s[l]]--;
                 l++;
             }
             if(mp[s[r]]==1)
             ans=max(ans,r-l+1);
             r++;
        }
        return ans;
    }
};