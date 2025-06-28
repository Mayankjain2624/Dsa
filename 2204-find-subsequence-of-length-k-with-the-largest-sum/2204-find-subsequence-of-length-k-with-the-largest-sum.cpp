class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<int> ans;
        stack<int>st;
        for(int i:nums){st.push(i);}
        sort(nums.begin(),nums.end(),greater<>());
        nums.resize(k);
        while(!st.empty())
        {
            int x=st.top();
            auto it=find(nums.begin(),nums.end(),x);
           if(it!=nums.end())
           {
           ans.push_back(x);
           nums.erase(it);
           }
           st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
