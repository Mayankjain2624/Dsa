class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int>st;
        int n=nums2.size();
        vector<int>ans(n);
        unordered_map<int,int>mp;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && st.top()<=nums2[i])
            {
                st.pop();
            }
            int x=nums2[i];
            if(!st.empty())
            mp[nums2[i]]=st.top();
            else
            mp[nums2[i]]=-1;
            st.push(x);
        }
        for(int i=0;i<nums1.size();i++){
            nums1[i]=mp[nums1[i]];
        }
        return nums1;
    }
};