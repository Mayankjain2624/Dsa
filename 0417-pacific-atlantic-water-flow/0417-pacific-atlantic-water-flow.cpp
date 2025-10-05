class Solution {
public:
    bool isValid(int i, int j, int n, int m) {
        if (i >= 0 && i < n && j >= 0 && j < m)
            return true;
        return false;
    }
    vector<int> dx = {1, -1, 0, 0};
    vector<int> dy = {0, 0, 1, -1};
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        queue<pair<int, int>> pacific, atlantic;
        vector<vector<int>> visp(n, vector<int>(m, 0)),visa(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            pacific.push({i, 0});
            visp[i][0] = 1;
        }
        for (int j = 1; j < m; j++) {
            pacific.push({0, j});
            visp[0][j] = 1;
        }
        // unordered_set<pair<int, int>> pr;
        while (!pacific.empty()) {
            int x = pacific.front().first;
            int y = pacific.front().second;
            // pr.insert({x, y});
            pacific.pop();
            visp[x][y] = 1;
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (isValid(nx, ny, n, m) && !visp[nx][ny] &&
                    heights[nx][ny] >= heights[x][y])
                    pacific.push({nx, ny});
            }
        }
        for (int i = 0; i < n; i++) {
            atlantic.push({i, m - 1});
            visa[i][m - 1] = 1;
        }
        for (int j = 0; j < m; j++) {
            atlantic.push({n - 1, j});
            visa[n - 1][j] = 1;
        }
        // unordered_set<pair<int, int>> ar;
        while (!atlantic.empty()) {
            int x = atlantic.front().first;
            int y = atlantic.front().second;
            // ar.insert({x, y});
            atlantic.pop();
            visa[x][y] = 1;
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (isValid(nx, ny, n, m) && !visa[nx][ny] &&
                    heights[nx][ny] >= heights[x][y])
                    atlantic.push({nx, ny});
            }
        }
        vector<vector<int>> ans;
       for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(visp[i][j]==1 && visa[i][j]==1)
            ans.push_back({i,j});
        }
       }
        // sort(ans.begin(), ans.end());
        return ans;
    }
};