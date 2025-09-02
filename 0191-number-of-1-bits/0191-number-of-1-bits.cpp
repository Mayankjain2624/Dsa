class Solution {
public:
    int hammingWeight(int n) {
        int cnt=0;
        while(n>0){
            // int x=n%2;
            if((n&1)==1)
            cnt++;
            n=n>>1;
        }
        return cnt;
    }
};