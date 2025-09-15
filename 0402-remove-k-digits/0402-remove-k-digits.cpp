class Solution {
public:
    string removeKdigits(string num, int k) {
        int n=num.length();
        if(k==n)
        return "0";
        stack<char>st;
        for(char ch:num){
            while(!st.empty() &&k>0 && (st.top()-'0')>(ch-'0'))
            {
                st.pop();
                // st.push(ch);
                k--;
            }
            // else
            st.push(ch);
        }
        // cout<<k<<endl;
        while(k){
            st.pop();
            k--;
        }
        cout<<st.size()<<endl;
        string ans;
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        int i=ans.length()-1;
        while(i>=0 && ans[i]=='0')
        {
            ans.pop_back();
            i--;
        }
       reverse(ans.begin(),ans.end());
       if(ans=="")
       return "0";
       return ans;
    }
};