class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) return 1; 
        long long nn = n; 
        if (nn < 0) {
            x = 1 / x;  
            if (nn <= -1e9 && n>1) return 0; 
            nn = -nn;  
        }
        double result = 1;
        while (nn > 0) {
            if (nn % 2 == 1) result *= x; 
            x *= x;                      
            nn /= 2;                   
        }
        return result;
    }
};
