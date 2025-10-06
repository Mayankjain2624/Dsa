class Solution {
  public:
  #define ll long long int
    int longestSubarray(vector<int>& arr, int k) {
        // code here
        int len=arr.size();
        unordered_map<ll,ll>prefixSum;
        prefixSum[0]=-1;
        ll currentSum=0;
        ll maxLen=0;
        for(ll i=0;i<len;i++){
            currentSum+=arr[i];
            ll needed=currentSum-k;
            if(prefixSum.count(needed))
            {
                maxLen=max(maxLen,i-prefixSum[needed]);
            }
            if(prefixSum.find(currentSum)==prefixSum.end())
            prefixSum[currentSum]=i;
        }
        return maxLen;
    }
};