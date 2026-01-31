class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        // code here
        int n=arr.size();
        unordered_map<int,int>sumi;
        int currSum=0;
        int ans=0;
        sumi[0]=0;
        for(int i=0;i<n;i++){
            currSum+=arr[i];
            int need=currSum-k;
            if(sumi.find(need)!=sumi.end())
            {
                ans=max(ans,i-sumi[need]+1);
                // cout<<ans<<" "<<i<<endl;
                
            }
            if(sumi.find(currSum)==sumi.end())
            sumi[currSum]=i+1;
        }
        return ans;
    }
};