class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int len=nums.size();
        vector<int>newArray(len);
        int positiveCounter=0;
        int negativeCounter=1;
        for(int i=0;i<len;i++){
               if(nums[i]>0)
               {
               newArray[positiveCounter]=nums[i];
               positiveCounter+=2;
               }
               else
               {
                newArray[negativeCounter]=nums[i];
                negativeCounter+=2;
               }
        }
        return newArray;
    }
};