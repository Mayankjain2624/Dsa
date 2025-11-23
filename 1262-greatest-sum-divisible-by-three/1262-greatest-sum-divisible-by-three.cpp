class Solution {
public:
    int smallestNum(vector<int> nums,int k){
        int small=40000;
        int sec=40000;
        int ab=40000;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%3==k){
                ab=min(ab,nums[i]);
            }
            if(nums[i]%3==((k*2)%3))
            {
                if(nums[i]<small){
                    sec=small;
                    small=nums[i];
                }
                else if(nums[i]<sec){
                    sec=nums[i];
                }
            }
        }
        return min(small+sec,ab);
    }
    int maxSumDivThree(vector<int>& nums) {
        int smallSum1=-1,smallSum2=-1;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        if(sum%3==2){
            return sum-smallestNum(nums,2);
        }
        else if(sum%3==1){
            return sum-smallestNum(nums,1);
        }
        return sum;
    }
};