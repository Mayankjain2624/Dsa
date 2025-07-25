class Solution {
public:
    int maxSum(vector<int>& nums) {
        set<int>st;
        int maxi=-1e9;
        for(int i:nums){
            if(i>0)
            st.insert(i);
            maxi=max(maxi,i);
        }
        int ans=0;
        for(int i:st)
        ans+=i;
        if(maxi<0)
        return maxi;
        return ans;
    }
};