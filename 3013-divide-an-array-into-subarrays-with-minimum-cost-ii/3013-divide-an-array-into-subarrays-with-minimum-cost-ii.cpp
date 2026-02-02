class Solution {
public:
    long long minimumCost(vector<int>& a, int k, int d) {
        long long ans=1e18, sum=0;
        int n=a.size(), cnt=0;
        set<int> st1, st2;
        map<int, int> mp1, mp2;
        for (int i=0; i<=d; i++) st1.insert(a[i]), mp1[a[i]]++;
        for (int i=1; i+d<n; i++) {
            st1.insert(a[i+d]);
            mp1[a[i+d]]++;
            if (mp1[a[i-1]]) {
                mp1[a[i-1]]--;
                if (!mp1[a[i-1]]) st1.erase(a[i-1]);
            } else {
                cnt--;
                sum-=a[i-1];
                mp2[a[i-1]]--;
                if (!mp2[a[i-1]]) st2.erase(a[i-1]);
            }
            while (cnt+1 < k) {
                cnt++;
                sum+=*st1.begin();
                st2.insert(*st1.begin());
                mp2[*st1.begin()]++;
                mp1[*st1.begin()]--;
                if (!mp1[*st1.begin()]) st1.erase(*st1.begin());
            }
            while (st1.size() && *st1.begin() < *st2.rbegin()) {
                int x=*st1.begin();
                int y=*st2.rbegin();
                sum-=y-x;
                st2.insert(x);
                st1.insert(y);
                mp2[x]++;
                mp2[y]--;
                mp1[x]--;
                mp1[y]++;
                if (!mp1[x]) st1.erase(x);
                if (!mp2[y]) st2.erase(y);
            }
            ans=min(ans, sum);
        }
        return ans+a[0];
    }
};