class Solution {
public:
    int countPartitions(vector<int>& nums) {
        long long int sum=0;
        for(auto it: nums) sum=sum+it;
        if(sum%2==0) return nums.size()-1;
        else return 0;
    }
};