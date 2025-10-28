class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int n=nums.size();
        vector<int> presum(n,0);
        vector<int>postsum(n,0);

        int j=n-1;
        int temp1=0;
        int temp2=0;
        for(int i=0;i<n;i++)
        {
            temp1+=nums[i];
            presum[i]=temp1;

            temp2+=nums[j];
            postsum[j]=temp2;
            j--;
        }
        int ans=0;

        // for(auto x:presum)
        // cout<<x<<" ";
        // cout<<endl;

        // for(auto x:postsum)
        // cout<<x<<" ";
        // cout<<endl;

        for(int i=0;i<n;i++)
        {
            if(nums[i]==0 && presum[i]==postsum[i])
            ans+=2;
            else if(nums[i]==0 && abs(presum[i]-postsum[i])==1)
            ans++;
        }

        return ans;
    }
};