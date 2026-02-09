class Solution {
public:
    int maxDepth(string s) {
        int no=0,nc=0;
        int ans=0;
        for(char c:s){
            if(c=='(')
            no++;
            else if(c==')')
            nc++;

                ans=max(ans,no-nc);
    
            
        }
        return ans;
    }
};