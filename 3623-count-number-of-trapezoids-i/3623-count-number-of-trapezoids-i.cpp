class Solution {
public:
    int MOD = 1e9 + 7;
    int countTrapezoids(vector<vector<int>>& a) {
        map<int,int>m;
        int x =0;
        for(int i =0;i<a.size();i++){
            m[a[i][1]]++;
        }
        for (auto& pair : m) {
            long long y = pair.second;
            if(y>1) {
                y = ((y*(y-1))/2)%MOD;
                if(y == 0) y = 1;  
            }
            else y = 0;
            pair.second = y;
            x += y;
        }
        long long ans = 0;
        for (const auto& pair : m) {
            ans += (1LL*(pair.second) * (x - pair.second))%MOD;
            x -= pair.second;
        }
        return (ans+MOD)%MOD;
    }
};

