class Solution
{
public:
    vector<char> dir = {'D', 'L', 'R', 'U'};
vector<int> dx = {1, 0, 0, -1};
vector<int> dy = {0, -1, 1, 0};

    bool isValid(int i, int j, int n, int m)
    {
        if (i >= 0 && i < n && j >= 0 && j < m)
            return true;
        return false;
    }
    void dfs(vector<string> &paths, vector<vector<int>> &maze, string &temp, int i, int j)
    {
        int n = maze.size();
        int m = maze[0].size();
        if (i == n - 1 && j == m - 1 && maze[n-1][m-1] == 1)
        {
            paths.push_back(temp);
        }
        maze[i][j]=0;
        for (int k = 0; k < 4; k++)
        {
            int nx = i + dx[k];
            int ny = j + dy[k];
            if (isValid(nx, ny, n, m) && maze[nx][ny] == 1)
            {
                temp.push_back(dir[k]);
                dfs(paths, maze, temp, nx, ny);
                temp.pop_back();
            }
        }
        maze[i][j]=1;
    }
    vector<string> ratInMaze(vector<vector<int>> &maze)
    {
        // code here
        vector<string> paths;
        string temp = "";
        dfs(paths, maze, temp, 0, 0);
        return paths;
    }
};