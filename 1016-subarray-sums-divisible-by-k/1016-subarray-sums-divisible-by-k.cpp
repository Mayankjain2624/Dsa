class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>pfs(n);
        pfs[0]=nums[0];
        for(int i=1;i<n;i++){
            pfs[i]=nums[i]+pfs[i-1];
        }
        map<int,int>mp;
        int ans=0;
        mp[0]++;
        for(int i=0;i<n;i++){
            int r=pfs[i]%k;
            if(r<0)
            r+=k;
            ans+=mp[r];
            mp[r]++;
        }
        return ans;
    }
};