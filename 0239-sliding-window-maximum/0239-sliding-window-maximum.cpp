class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        deque<int>dq;
        vector<int>ans;
        if(k==1)
        return nums;
        for(int i=0;i<n;i++){
            while(!dq.empty() && nums[dq.back()]<=nums[i])
            dq.pop_back();
            while(!dq.empty() && dq.front()<=i-k)
            dq.pop_front();
            dq.push_back(i);
            if(i>=(k-1))
            ans.push_back(nums[dq.front()]);
        }
       return ans;
    }
};