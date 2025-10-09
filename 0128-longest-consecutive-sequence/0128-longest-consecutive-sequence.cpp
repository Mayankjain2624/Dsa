class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>st;
        for(int i:nums){
            st.insert(i);
        }
        int longest=0;
        for(auto &it:st){
            if(st.find(it-1)==st.end())
            {
                int x=it;
                int cnt=1;
                while(st.find(x+1)!=st.end()){
                    x=x+1;
                    cnt++;
                }
                longest=max(longest,cnt);
            }
        }
        return longest;
    }
};