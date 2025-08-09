class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0)
        return false;
            int x=log2(n);
        if(1<<x==n)
        return true;
        return false;
        
    }
};