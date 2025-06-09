class Solution {
public:
    int findKthNumber(int n, int k) {
        int current = 1;
        k--;
        
        while (k > 0) {
            int count = countSteps(n, current, current + 1);
            if (count <= k) {
                current++;
                k -= count;
            } else {
                current *= 10;
                k--;
            }
        }
        
        return current;
    }

    int countSteps(int n, long long curr, long long next) {
        int steps = 0;
        while (curr <= n) {
            steps += min(n + 1, (int)next) - curr;
            curr *= 10;
            next *= 10;
        }
        return steps;
    }
};