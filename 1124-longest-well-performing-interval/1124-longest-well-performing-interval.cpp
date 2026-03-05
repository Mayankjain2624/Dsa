class Solution {
public:
    int longestWPI(vector<int>& hours) {
        int longest_interval = 0;
        int n = hours.size();
        int cnt = 0;
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            if (hours[i] > 8)
                cnt++;
            else
                cnt--;
            if(cnt>0)
            longest_interval = max(longest_interval,i+1);
            else if (mp.find(cnt-1) != mp.end()) {
                int previ = mp[cnt-1];
                int curri = i;
                longest_interval = max(longest_interval, curri - previ);
            }
            if(mp.find(cnt)==mp.end())
            mp[cnt] = i;
        }
        return longest_interval;
    }
};                  