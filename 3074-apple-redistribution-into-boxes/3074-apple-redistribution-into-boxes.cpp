class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int n = apple.size(), m = capacity.size();
        sort(capacity.rbegin(), capacity.rend());
        int ans = 0, rem = accumulate(apple.begin(), apple.end(), 0);

        for(int i=0; i<m; i++){
            ans++;
            rem -= capacity[i];
            if(rem <= 0) return ans;
        }

        return m;
    }
};