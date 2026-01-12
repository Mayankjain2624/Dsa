class Solution {
public:
    bool check(vector<int>& nums) {
        int prev=nums[0];
        int mini=nums[0];
        int flag=0;
        int n=nums.size();
        for(int i=1;i<n;i++){
            if(nums[i]>=prev && flag==0)
            {
                prev=nums[i];
                continue;
            }
            else if(flag==0 && nums[i]<prev && nums[i]<=mini){
                flag=1;
                prev=nums[i];
            }
            else if(flag && nums[i]>=prev && nums[i]<=mini){
                flag=1;
                prev=nums[i];
            }
            else
            return false;
        }
        return true;
    }
};