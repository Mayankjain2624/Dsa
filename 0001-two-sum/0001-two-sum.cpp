class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        unordered_map<int,int>ump;
        for(int i=0;i<n;i++){
            int need=target-nums[i];
            auto it=ump.find(need);
            if(it!=ump.end())
            return {ump[need],i};
            else
            ump[nums[i]]=i;
        }
        return {};
    }
};