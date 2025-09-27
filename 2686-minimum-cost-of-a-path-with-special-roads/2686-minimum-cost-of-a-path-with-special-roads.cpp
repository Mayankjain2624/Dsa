class Solution {
public:
int dist(int x1,int y1,int x2,int y2){
    return abs(x1-x2)+abs(y2-y1);
}
    int minimumCost(vector<int>& start, vector<int>& target, vector<vector<int>>& specialRoads) {
        int tx=target[0];
        int ty=target[1];
        // map<int,vector<pair<int,int>>>adj;
        map<pair<int,int>,int>mp;
        mp[{tx,ty}]=dist(start[0],start[1],target[0],target[1]);
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<>>pq;
        pq.push({0,{start[0],start[1]}});
        while(!pq.empty()){
            int cost=pq.top().first;
            int x=pq.top().second.first;
            int y=pq.top().second.second;
            pq.pop();
            if(x==tx && y==ty)
            return cost;
            int dt=dist(x,y,tx,ty);
            if(mp[{tx,ty}]>(cost+dt))
            pq.push({cost+dt,{tx,ty}});
            for(auto &roads:specialRoads){
                int si=roads[0];
                int sj=roads[1];
                int ei=roads[2];
                int ej=roads[3];
                int sc=roads[4];
                int d1=dist(x,y,si,sj);
                int d2=dist(x,y,ei,ej);
                if (mp.find({si, sj}) == mp.end() || mp[{si, sj}] > (d1 + cost))
                {
                    mp[{si,sj}]=cost+d1;
                    pq.push({cost+d1,{si,sj}});
                }
                int nc=INT_MAX;
                if(x==si && y==sj){
                     nc=cost+sc;
                }
                else
                nc=cost+d2;

                if(mp.find({ei,ej})==mp.end() || mp[{ei,ej}]>nc)
                {
                mp[{ei,ej}]=nc;
                pq.push({nc,{ei,ej}});
                }
            }
        }
        return mp[{tx,ty}];
    }
};