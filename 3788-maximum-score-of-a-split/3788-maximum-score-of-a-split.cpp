class Solution {
public:
    long long maximumScore(vector<int>& nums) {
        int n=nums.size();
        vector<long long>prefix(n);
        vector<long long>minValue(n);
        minValue[n-1]=nums[n-1];
        prefix[0]=nums[0];
        for(int i=1;i<n;i++)
        prefix[i]=nums[i]+prefix[i-1];
        for(int i=n-2;i>=0;i--)
        minValue[i]=min(minValue[i+1],1LL*nums[i]);
        long long score=LLONG_MIN;
        for(int i=0;i<n-1;i++){
            score=max(score,prefix[i]-minValue[i+1]);
        }
     return score;
    }
};