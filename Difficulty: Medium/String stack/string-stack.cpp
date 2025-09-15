class Solution {
  public:
    bool stringStack(string &pat, string &tar) {
        // code here
        int n=pat.size();
        int m=tar.size();
        n--;
        m--;
        int cnt=0;
        while(m>=0 && n>=0){
            if(pat[n]==tar[m])
            {
                n--;
                m--;
                // if(cnt%2!=0)
                // return false;
                // cnt=0;
                
            }
            else
            {
                n-=2;
                // cnt++;
            }
        }
        if(m==-1)
        return true;
        else
        return false;
    }
};