class Solution {
        const vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
public:
    bool dfs(vector<vector<char>>& board,int i,int j,const string &word,int l,int m,int n){
        if(l==word.size())
        return true;
        if(i<0 || j<0 || i>=m || j>=n)
        return false;
        if(board[i][j]!=word[l])
        return false;
        char ch=board[i][j];
        board[i][j]='#';
         for(auto &it:dirs){
            int ni=i+it.first;
            int nj=j+it.second;
            if (dfs(board, ni, nj, word, l + 1,m,n))
                return true;
         }
         board[i][j]=ch;
        return false;
    }
    bool exist(vector<vector<char>>& board,const string& word) {
         int m = board.size(), n = board[0].size();
         if(word.size()>m*n)
         return false;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == word[0] && dfs(board, i, j, word, 0,m,n))
                    return true;
            }
        }
        return false;
    }
};