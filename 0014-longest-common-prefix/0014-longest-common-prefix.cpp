class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int ans=0;
        int x=INT_MAX;
        int n=strs.size();
        for(string s:strs){
            x=min(x,(int)s.length());
        }
        int i=0;
        while(i<x){
            char ch=strs[0][i];
            int flag=1;
            for(int j=0;j<n;j++){
                if(strs[j][i]==ch){
                    continue;
                }
                else
                {
                    return strs[0].substr(0,i);
                }
        }
            i++;
        }
        return strs[0].substr(0,i);
    }
};