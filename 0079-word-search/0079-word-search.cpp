class Solution {
public:
    bool dfs(vector<vector<char>>& board,int i,int j,string &word,int l){
        if(l==word.size())
        return true;
        if(i<0 || j<0 || i>=board.size() || j>=board[0].size())
        return false;
        if(board[i][j]!=word[l])
        return false;

        char ch=board[i][j];
        board[i][j]='#';
         vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
         for(auto &it:dirs){
            int ni=i+it.first;
            int nj=j+it.second;
            if(dfs(board,ni,nj,word,l+1))
            return true;
         }
        board[i][j]=ch;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
         int m = board.size(), n = board[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dfs(board, i, j, word, 0))
                    return true;
            }
        }
        return false;
    }
};