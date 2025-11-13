class Solution {
public:
    int maxOperations(string s) {
        int n= s.length();
        vector<int>ps(n,0);
        int count= (s[0]=='1');
        bool flag= false;
        for(int i=1;i<n;i++){
            if(s[i]=='0' && !flag){
                flag= true; 
                ps[i]= count;
            }
            else if(s[i]=='1'){
                flag= false;
                count++;
            }
        }
        
        int ans=0;
        for(int num: ps){
            ans += num;
        }
        return ans;
    }
};