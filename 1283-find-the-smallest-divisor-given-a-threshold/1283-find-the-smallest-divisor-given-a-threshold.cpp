class Solution {
public:
#define ll long long int
    int smallestDivisor(vector<int>& nums, int threshold) {
        ll l=1;
        ll r=*max_element(nums.begin(),nums.end());
        ll ans=0;
        while(l<=r){
            ll mid=l+(r-l)/2;
            int k=0;
            for(int i:nums){
                k+=ceil(i*1.0/mid);
            }
            if(k<=threshold){
                ans=mid;
                r=mid-1;
            }
            else
            l=mid+1;
        }
         return ans;
    }
};