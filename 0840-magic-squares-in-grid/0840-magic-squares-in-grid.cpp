class Solution {
public:
    bool isMagicSquare(vector<vector<int>>& grid, int& i, int& j) {
        unordered_set<int> st;

        for (int r = i; r < i + 3; r++) {
            for (int c = j; c < j + 3; c++) {
                if (grid[r][c] == 0 || grid[r][c] > 9)
                    return false;
                st.insert(grid[r][c]);
            }
        }

        if (st.size() < 9)
            return false;

        int row1Sum = grid[i][j] + grid[i][j + 1] + grid[i][j + 2];
        int row2Sum = grid[i + 1][j] + grid[i + 1][j + 1] + grid[i + 1][j + 2];
        int row3Sum = grid[i + 2][j] + grid[i + 2][j + 1] + grid[i + 2][j + 2];

        int col1Sum = grid[i][j] + grid[i + 1][j] + grid[i + 2][j];
        int col2Sum = grid[i][j + 1] + grid[i + 1][j + 1] + grid[i + 2][j + 1];
        int col3Sum = grid[i][j + 2] + grid[i + 1][j + 2] + grid[i + 2][j + 2];

        int diag1Sum = grid[i][j] + grid[i + 1][j + 1] + grid[i + 2][j + 2];
        int diag2Sum = grid[i][j + 2] + grid[i + 1][j + 1] + grid[i + 2][j];

        return row1Sum == row2Sum && row2Sum == row3Sum && row3Sum == col1Sum &&
               col1Sum == col2Sum && col2Sum == col3Sum &&
               col3Sum == diag1Sum && diag1Sum == diag2Sum;
    }

    int numMagicSquaresInside(vector<vector<int>>& grid) {
        if (grid.size() < 3 || grid[0].size() < 3)
            return 0;

        int result = 0;
        for (int i = 0; i <= grid.size() - 3; i++)
            for (int j = 0; j <= grid[0].size() - 3; j++)
                if (isMagicSquare(grid, i, j))
                    result++;

        return result;
    }
};