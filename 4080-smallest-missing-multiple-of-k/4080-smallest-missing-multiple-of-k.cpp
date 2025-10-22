class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        int ans = k;
        for(int i=0;i<102;i++){
            if(mp.find(ans)==mp.end()) return ans;
            ans = ans+k;
        }
        return -1;
    }
};