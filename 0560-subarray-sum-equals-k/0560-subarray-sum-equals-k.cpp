class Solution {
public:
#define ll long long int
    int subarraySum(vector<int>& nums, int k) {
                int len=nums.size();
                int numberOfSubarrays=0;
        // int startPointer=0;
        // int endPointer=0;
        // int maxLen=0;
        // int ans=0;
        // int currentSum=nums[endPointer];
        // if(k==0)
        // return 0;
        // while(endPointer<len){
        //     if(currentSum<=k){
        //         if(currentSum==k)
        //         {
        //             ans++;
        //         maxLen=max(maxLen,endPointer-startPointer+1);
        //         }
        //         endPointer++;
        //         if(endPointer==len)
        //         break;
        //         currentSum+=nums[endPointer];
        //     }
        //     else
        //     {
        //         currentSum-=nums[startPointer];
        //         startPointer++;
        //     }
        // }
        // return ans;
        unordered_map<ll,vector<ll>>prefixSum;
        prefixSum[0].push_back(-1);
        ll currentSum=0;
        // ll maxLen=0;
        for(ll i=0;i<len;i++){
            currentSum+=nums[i];
            ll needed=currentSum-k;
            if(prefixSum.count(needed))
            {
                // maxLen=max(maxLen,i-prefixSum[needed]);
                numberOfSubarrays+=prefixSum[needed].size();
            }
            prefixSum[currentSum].push_back(i);
        }
        return numberOfSubarrays;
        
    }
};