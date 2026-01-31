class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate=-1;
        int n=nums.size();
        int votes=0;
        for(int i:nums)
        {
           if(votes==0)
           {
            candidate=i;
            votes++;
           }
           else{
            if(candidate==i)
            votes++;
            else
            votes--;
           }
        }
        int cnt=0;
        for(int i:nums){
            if(i==candidate)
            cnt++;
        }
        if(cnt>n/2)
        return candidate;
        else
        return -1;
    }
};