class Solution {
public:
int helper(vector<int>&nums,int sum){
    int split=1;
    int curr=0;
    for(int i:nums){
        curr+=i;
        if(curr>sum){
            curr=i;
            split++;
        }
    }
    // cout<<split<<endl;
    return split;
}
    int splitArray(vector<int>& nums, int k) {
        int l=0,r=0;
        for(int i:nums){
            l=max(l,i);
            r+=i;
        }
        int ans=1e9;
        while(l<=r){
            int mid=(l+r)/2;
            int split=helper(nums,mid);
            cout<<mid<<" "<<split<<endl;
            if(split>k){
                l=mid+1;
            }
            else
            {
                r=mid-1;
                ans=min(ans,mid);
            }
        }
        return ans;
    }
};