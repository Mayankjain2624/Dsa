class Solution {
  public:
    int maxSubarraySum(vector<int> &arr) {
        // Code here
        int n=arr.size();
        int ans=INT_MIN;
        int prevBest=0;
        for(int i=0;i<n;i++){
            if(prevBest>=0)
            prevBest+=arr[i];
            else
            prevBest=arr[i];
            ans=max(ans,prevBest);
        }
        return ans;
    }
};