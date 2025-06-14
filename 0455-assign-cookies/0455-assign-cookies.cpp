class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int l=0,r=0;
        int gn=g.size();
        int sn=s.size();
        while(l<gn && r<sn){
            if(g[l]<=s[r])
            {
                l++;
                r++;
            }
            else{
              r++;
            }

        }
        return l;
    }
};