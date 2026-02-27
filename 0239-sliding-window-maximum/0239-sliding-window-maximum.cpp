class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
       deque<int>dq;
       vector<int>maxi;
       for(int i=0;i<k-1;i++)
       {
          while(!dq.empty() && nums[dq.back()]<nums[i])
           dq.pop_back();
           dq.push_back(i);
       }
       for(int i=k-1;i<n;i++){
           while(!dq.empty() && dq.front()<=i-k)
           dq.pop_front();
           while(!dq.empty() && nums[dq.back()]<nums[i])
           dq.pop_back();
           dq.push_back(i);
           maxi.push_back(nums[dq.front()]);
       }
       return maxi;
    }
};