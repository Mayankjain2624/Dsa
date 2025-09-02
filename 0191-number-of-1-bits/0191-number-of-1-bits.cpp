class Solution {
public:
    int hammingWeight(int n) {
        int cnt=0;
        while(n>0){
            int x=n%2;
            if(x==1)
            cnt++;
            n/=2;
        }
        return cnt;
    }
};