class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int cmax=nums[0];
        int cmin=nums[0];
        if(n==1)
        return nums[0];
        int ans=nums[0];
        for(int i=1;i<n;i++){
            cout<<cmax<<" "<<cmin<<endl;
            int tcmax=cmax;
            int tcmin=cmin;
            cmax=max({tcmax*nums[i],tcmin*nums[i],nums[i]});
            cmin=min({tcmax*nums[i],tcmin*nums[i],nums[i]});
            ans=max(ans,cmax);
            cout<<ans<<endl;
        }
        return max(ans,INT_MIN);
    }
};