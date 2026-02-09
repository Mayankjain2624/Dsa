class Solution {
public:
    string removeOuterParentheses(string s) {
        int n=s.length();
        int depth=0;
        int start=0;
        string ans;
        for(int i=0;i<n;i++){
                if(s[i]=='(')
                depth++;
                else
                depth--;
                if(depth==0){
                for(int j=start+1;j<i;j++){
                    ans.push_back(s[j]);
                }
                start=i+1;
                }
        }
        return ans;
    }
};