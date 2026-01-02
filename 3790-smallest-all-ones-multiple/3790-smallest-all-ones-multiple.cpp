class Solution {
public:
    int minAllOneMultiple(int k) {
        if(k%2==0 || k%5==0)
        return -1;
        else
        {
             long long n=1;
             for(int i=1;i<=k;i++)
             {
                if(n%k==0)
                return i;
                n=(n*10+1)%k;
             }
        }
        return -1;
    }
};