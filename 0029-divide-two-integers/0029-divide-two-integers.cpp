class Solution {
public:
    int divide(int dividend, int divisor) {
        long int count = 0;
        long int y = dividend;
        long int x = divisor;
        int flag = 1;
        if (y * x < 0) {
            flag = -1;
        }
        y = abs(y);
        x = abs(x);
        long int val = 1;
        while (y >= x) {
            y = y - val * x;
            count = count + val;
            if (val * 2 * x > y)
            {
                val = 1;
            }
            else val = val * 2;
        }
        if (flag * count > INT_MAX)
            return INT_MAX;
        if (flag * count < INT_MIN)
            return INT_MIN;
        return count * flag;
    }
};