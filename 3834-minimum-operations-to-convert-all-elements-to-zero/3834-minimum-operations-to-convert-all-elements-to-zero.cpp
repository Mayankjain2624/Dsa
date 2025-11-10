class Solution {
public:
vector<int>findnse(vector<int>arr)
{
    int n=arr.size();
    stack<int>st;
    vector<int>ans(n,n);
    for(int i=n-1;i>=0;i--)
    {
        while(!st.empty() && arr[st.top()]>=arr[i])
        st.pop();
        if(!st.empty())
        ans[i]=st.top();
        st.push(i);
    }
    return ans;
}
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        map<int,int>mp;
        vector<int>nse=findnse(nums);
        int cnt=0;
        for(int i=0;i<n;i++){
            if(nums[i]==0)
            continue;
            if(!mp.count(nums[i])|| i>mp[nums[i]])
            {
                cnt++;
            }
                mp[nums[i]]=nse[i];
        }
        return cnt;
        // if(nums[])
    }
};