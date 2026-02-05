class Solution {
public:
    int leastInterval(vector<char>& tasks, int k) {
        int n=tasks.size();
        int next[26] = {100000};
        map<char, int> freq;
        for (char c : tasks) {
            freq[c]++;
            next[c-'A'] = 1;
        }
        int counter = 1;
        int nc = 0;
        while (nc < n) {
            priority_queue<pair<int, char>, vector<pair<int, char>>> pq;
            for (char ch = 'A'; ch <= 'Z'; ch++) {
                if (next[ch - 'A'] <= counter && freq[ch]>0) {
                    pq.push({freq[ch], ch});
                }
            }
            if (pq.empty()) {
                counter++;
                continue;
            }
            char ch = pq.top().second;
            freq[ch]--;
            if (freq[ch] == 0) {
                next[ch - 'A'] = 100000;
            }
            else
            next[ch - 'A'] = counter + k + 1;
            counter++;
            nc++;
        }
    return counter-1;
    }
};