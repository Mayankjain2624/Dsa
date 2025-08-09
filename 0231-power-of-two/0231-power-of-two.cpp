class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0)
        return false;
        if(n==0)
        return false;
            int x=log2(abs(n));
        if(1<<x==abs(n))
        return true;
        return false;
        
    }
};