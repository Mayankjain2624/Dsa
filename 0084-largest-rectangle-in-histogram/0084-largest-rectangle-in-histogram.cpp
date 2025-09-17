class Solution {
public:
    int largestRectangleArea(vector<int>&nums) {
        int n=nums.size();
        stack<int>st1;
        vector<int>pse(n),nse(n);
        for(int i=0;i<n;i++){
             while(!st1.empty() && nums[st1.top()]>=nums[i])
             st1.pop();
             if(st1.empty())
             pse[i]=-1;
             else
             pse[i]=st1.top();
             st1.push(i);
        }
        stack<int>st2;
        for(int i=n-1;i>=0;i--){
            while(!st2.empty() && nums[st2.top()]>nums[i])
            st2.pop();
            if(st2.empty())
            nse[i]=n;
            else
            nse[i]=st2.top();
            st2.push(i);
        }
        for(int i:nse)
        cout<<i<<" ";
        cout<<endl;
        for(int i:pse)
        cout<<i<<" ";
        cout<<endl;
        int ans=0;
        for(int i=0;i<n;i++){
     int area=(nse[i]-pse[i]-1)*nums[i];
     ans=max(ans,area);
        }
        return ans;
    }
};