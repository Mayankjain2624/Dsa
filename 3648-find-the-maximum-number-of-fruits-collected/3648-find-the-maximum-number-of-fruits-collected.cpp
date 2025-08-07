class Solution {
public:
    int maxCollectedFruits(vector<vector<int>>& fruits) {
    int n = fruits.size(), res = 0;
    for (int i = 0; i < n; i++)
        res += fruits[i][i];

    for (int turn = 0; turn < 2; turn++) {
        if (turn == 1) {
            for (int i = 0; i < n; i++)
                for (int j = i + 1; j < n; j++)
                    swap(fruits[i][j], fruits[j][i]);
        }

        vector<int> prev(n, -1), cur(n, -1);
        prev[n - 1] = fruits[0][n - 1];

        for(int r = 1; r < n - 1; r++) {
            fill(cur.begin(), cur.end(), -1);
            for (int i = 0; i < n; i++) {
                if (prev[i] < 0)
                    continue;
                if (i > 0) 
                    cur[i - 1] = max(cur[i - 1], prev[i] + fruits[r][i - 1]);
                if (i < n - 1) 
                    cur[i + 1] = max(cur[i + 1], prev[i] + fruits[r][i + 1]);
                cur[i] = max(cur[i], prev[i] + fruits[r][i]);
            }
            swap(prev, cur);
        }
        res += prev[n - 1];
    }
    return res;
    }
};