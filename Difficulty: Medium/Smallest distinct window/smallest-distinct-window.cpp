class Solution {
  public:
    int findSubString(string& str) {
        // code here
        int l=0;
        int r=0;
        int n=str.length();
        map<int,int>mp;
        set<char>st;
        for(char c:str){
            st.insert(c);
        }
        int x=st.size();
        int cdc=0;
        int ans=INT_MAX;
        while(r<n){
            mp[str[r]]++;
            while(mp.size()==x){
                ans=min(ans,r-l+1);
                mp[str[l]]--;
                if(mp[str[l]]==0)
                mp.erase(str[l]);
                l++;
            }
            r++;
        }
        return ans;
    }
};