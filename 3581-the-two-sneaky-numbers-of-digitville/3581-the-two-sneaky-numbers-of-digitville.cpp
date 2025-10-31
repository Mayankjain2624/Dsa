class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        int zeroCnt=0;
        vector<int>ans;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int x=nums[i];
            if(x<0)
            x+=102;
            if(nums[x]<0)
            {
                ans.push_back(x);
            }
            else
            {
                nums[x]=(nums[x]-102);
            }
        }
        return ans;
    }
};