class Solution {
public:
    string minRemoveToMakeValid(string s) {
        // stack<pair<char,int>>st;
        stack<int>st;
        for(int i=0;i<s.length();i++){
            char ch=s[i];
            if(ch=='(')
            st.push(i);
            else if(ch==')'){
                if(!st.empty() && s[st.top()]=='(')
                st.pop();
                else
                st.push(i);
            }
            else
            continue;
        }
        while(!st.empty()){
            s.erase(st.top(),1);
            // cout<<st.top().first<<" "<<st.top().second<<" ";
            st.pop();
        }
        return s;
    }
};