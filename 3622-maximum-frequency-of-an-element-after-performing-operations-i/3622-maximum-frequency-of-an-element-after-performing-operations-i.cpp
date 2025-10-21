class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int i = 0;
        int j = 0;
        int l = 0;
        int points = 0;
        int current = 0;
        int maxi = 0;
        while (1) {

            current = INT_MAX;
            if (i < n)
                current = min(current, nums[i]);
            if (j < n)
                current = min(current, nums[j] - k);
            if (l < n)
                current = min(current, nums[l] + k);
            if (current == INT_MAX)
                break;
            while ((j < n) && ((nums[j] - k) == current)) {
      
                points++;
                j++;
            }
            int at_point = 0;
            while ((i < n) && (nums[i] == current)) {
        
                at_point++;
                i++;
            }
         
            if (points - at_point > numOperations)
                maxi = max(maxi, numOperations + at_point);
            else
                maxi = max(maxi, points);

            while ((l < n) && (nums[l]+k == current)) {
             
                points--;
                l++;
            }
        }
        return maxi;
    }
};
