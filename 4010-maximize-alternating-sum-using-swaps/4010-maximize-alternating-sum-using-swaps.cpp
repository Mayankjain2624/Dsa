#include <bits/stdc++.h>
using namespace std;
#define ll long long int
class DisjointSet {

public:
    vector<int> rank, parent, size;
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }
    int findPar(int u) {
        if (u == parent[u])
            return u;
        return parent[u] = findPar(parent[u]);
    }
    void UnionBySize(int u, int v) {
        int ulp_u = findPar(u);
        int ulp_v = findPar(v);
        if (ulp_u == ulp_v)
            return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        } else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums, vector<vector<int>>& swaps) {
        int n=nums.size();
        // int n = swaps.size();
        DisjointSet ds(n);
        for (auto& it : swaps) {
            int i = it[0];
            int j = it[1];
            ds.UnionBySize(i, j);
        }
        map<int,vector<int>>groups;
        for(int i=0;i<n;i++){
           ds.UnionBySize(i,ds.parent[i]);
        }
        for(int i=0;i<n;i++){
            groups[ds.parent[i]].push_back(i);
        }
        ll ans=0;
        for(auto &it:groups){
           vector<int>temp;
           int odd=0,even=0;
           for(int &i:it.second){
            temp.push_back(nums[i]);
            if(i&1) 
            odd++;
            else
            even++;
           }
           sort(temp.begin(),temp.end(),greater<>());
           ll localans=0;
           for(int i=0;i<temp.size();i++){
              if(i<even)
              localans+=temp[i];
              else
              localans-=temp[i];
           }
           ans+=localans;
        }
        return ans;
    }
};