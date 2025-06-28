class Solution {
public:
    bool isPalindrome(string s) {
         string sc="",scc;
         for(char c:s){
            if(c>='A' && c<='Z')
            sc+=(c+32);
            else if(c>='a' && c<='z')
            sc+=c;
            else if(c>='0' && c<='9')
            sc+=c;
         }
            scc=sc;
            reverse(sc.begin(),sc.end());
            if(scc==sc)
            return true;
            else
            return false;
    }
};