class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.size();
        int state0[26] = {0};
        queue<int> state1[26];
        int state2[26] = {0};
        int ans=0;
        for(int i=0; i<n; i++)
        {
            int c = s[i]-'a';
            ans+= state2[c];
            state2[c] = 0;
            while(!state1[c].empty())
            {   // got 2nd char add to 1st char counter
                state2[state1[c].front()]++;
                state1[c].pop();
            }
            if(state0[c]==0)
            {   // after 1st time of char wait for 26 2nd
                for(int j=0; j<26; j++)
                {
                    state1[j].push(c);
                }
                state0[c]=1;
            }
        }
        return ans;
    }
};