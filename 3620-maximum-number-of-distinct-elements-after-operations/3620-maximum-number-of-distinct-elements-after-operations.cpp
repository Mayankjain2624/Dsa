class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        
        int ans = 1;
        nums[0] -= k;
        int last = nums[0];
        
        for(int i= 1; i < nums.size() ;i++){
            if(nums[i] + k <= last) continue;
            else{
                nums[i] = max(nums[i] - k, last+ 1);
                last = nums[i];
                ans++;                
            }
            
        }
        return ans;


        
    }
};