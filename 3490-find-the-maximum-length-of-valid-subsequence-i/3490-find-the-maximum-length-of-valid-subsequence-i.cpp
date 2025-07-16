class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int even = 0, odd = 0;
        for (int i: nums) {
            if (i % 2 == 0) even++;
            else odd++;
        }

        int evenalt = 0, oddalt = 0;
        for (int i : nums) {
            if (i % 2 == 0)
                evenalt= max(evenalt, oddalt + 1);
            else
                oddalt = max(oddalt, evenalt + 1);
        }

        return max({even,odd, evenalt, oddalt});
    }
};