class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size();
        int m = moveTime[0].size();

        vector<vector<int>> time(n, vector<int>(m, 1e9+2501));
        time[0][0] = 0;

        vector<int> dx = {1, -1, 0, 0};
        vector<int> dy = {0, 0, 1, -1};

        // priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>,
        //                greater<tuple<int, int, int>>>
        //     pq;
        queue<tuple<int, int, int>>pq;
        pq.push({0, 0, 0});

        while (!pq.empty()) {
            auto [currTime, x, y] = pq.front();
            pq.pop();
            if (currTime > time[x][y])
                continue;
            for (int d = 0; d < 4; d++) {
                int nx = x + dx[d];
                int ny = y + dy[d];

                if (nx < 0 || ny < 0 || nx >= n || ny >= m)
                    continue;
                 
                int nextTime;
                if((currTime + 1)<=moveTime[nx][ny])
                nextTime=moveTime[nx][ny]+1;
                else
                nextTime=currTime+1;

                if (nextTime < time[nx][ny]) {
                    time[nx][ny] = nextTime;
                    pq.push({nextTime, nx, ny});
                }
            }
        }

        return time[n-1][m-1];
    }
};
