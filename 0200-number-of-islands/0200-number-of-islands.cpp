class Dsu {
public:
    vector<int> parent, size;
    Dsu(int n) {
        parent.resize(n);
        size.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }
    int find(int u) {
        if (parent[u] == u) {
            return u;
        }
           return parent[u] = find(parent[u]);
    }
    void unite(int u, int v) {
        int ulp_u = find(u);
        int ulp_v = find(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] > size[ulp_v]) {
            parent[ulp_v] = ulp_u;
            size[ulp_u]+=size[ulp_v];
        } else {
            parent[ulp_u] = ulp_v;
            size[ulp_v]+=size[ulp_u];
        }
    }
};
class Solution {
public:
    bool isValid(int x, int y, int n, int m) {
        if (x >= 0 && x < n && y >= 0 && y < m)
            return true;
        return false;
    }
    vector<int> di = {1, 0, -1, 0};
    vector<int> dj = {0, 1, 0, -1};
    // void dfs(vector<vector<char>>& grid, int x, int y, int n, int m) {
    //     grid[x][y] = '0';
    //     for (int i = 0; i < 4; i++) {
    //         int nx = x + di[i];
    //         int ny = y + dj[i];
    //         if (isValid(nx, ny, n, m) && grid[nx][ny] == '1') {
    //             dfs(grid, nx, ny, n, m);
    //         }
    //     }
    // }
    int index(int i, int j, int m) { return i * m + j; }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int cnt = 0;
        int s = n * m + 1;
        Dsu dsu(s);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1') {
                    for (int d = 0; d < 4; d++) {
                        int nx = i + di[d];
                        int ny = j + dj[d];
                        if (isValid(nx, ny, n, m) && grid[nx][ny] == '1') {
                            dsu.unite(index(i, j, m), index(nx, ny, m));
                        }
                    }
                }
            }
        }
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    int ti = index(i, j, m);
                    if (dsu.parent[ti] == ti && grid[i][j] == '1')
                        cnt++;
                }
            }
        return cnt;
    }
};