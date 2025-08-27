class Dsu
{
    vector<int> size, parent;

public:
    Dsu(int n)
    {
        size.resize(n + 1, 1);
        parent.resize(n + 1, 0);
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }
    int findPar(int u)
    {
        if (u == parent[u])
            return u;
        else
            return parent[u] = findPar(parent[u]);
    }
    void UnionBySize(int u, int v)
    {
        int ulp_u = findPar(u);
        int ulp_v = findPar(v);
        if (ulp_u == ulp_v)
            return;
        if (size[ulp_u] < size[ulp_v])
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
class Solution
{
public:
    vector<int> dx = {1, -1, 0, 0};
    vector<int> dy = {0, 0, -1, 1};
    bool isvalid(int x, int y, int n, int m)
    {
        if (x >= 0 && x < n && y >= 0 && y < m)
            return true;
        return false;
    }
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators)
    {
        Dsu ds(10000);
        int k = operators.size();
        vector<int> ans(k + 1, 0);
        // vector<vector<int>> grid(n, vector<int>(m, 0));
        vector<int> grid(10000, 0);
        int cnt = 0;
        for (int i = 0; i < k; i++)
        {
            int x = operators[i][0];
            int y = operators[i][1];
            // int already = 0;
            if(grid[x*100+y])
            {
                ans[i+1]=cnt;
                continue;
            }
            cnt++;
            grid[x*100+y]=1;
            for (int di = 0; di < 4; di++)
            {
                int nx = x + dx[di];
                int ny = y + dy[di];
                if (isvalid(nx, ny, n, m))
                {
                    int ipu = 0, ipv = 0;
                    if (grid[nx * 100 + ny])
                    {
                        int u = x * 100 + y;
                        int v = nx * 100 + ny;
                        ipu = ds.findPar(u);
                        ipv = ds.findPar(v);
                        ds.UnionBySize(u, v);
                    }
                    if (ipu != ipv)
                        cnt--;
                }
            }
            ans[i + 1] = cnt;
        }
        ans.erase(ans.begin());
        return ans;
    }
};
