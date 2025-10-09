class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt=1;
        int x=nums[0];
        for(int i=1;i<nums.size();i++){
            if(cnt==0)
            {
                x=nums[i];
            }
            if(x==nums[i])
            cnt++;
            else
            cnt--;
        }
        cnt=0;
       for(int i:nums){
          if(i==x)
          cnt++;
       }
       if(cnt>(nums.size()/2))
       return x;
       else
       return -1;
    }
};