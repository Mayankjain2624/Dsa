class Solution {
public:
    int maxDifference(string s) {
        map<int,int>mp;
        for(char ch:s){
            mp[ch]++;
        }
        int fa1=0;
        int fa2=1e9;
        for(auto &it:mp){
            int f=it.second;
            if(f&1)
            fa1=max(fa1,f);
            else
            fa2=min(fa2,f);
        }
        return fa1-fa2;
    }
};