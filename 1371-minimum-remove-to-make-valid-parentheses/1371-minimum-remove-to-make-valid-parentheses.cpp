class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<pair<char,int>>st;
        for(int i=0;i<s.length();i++){
            char ch=s[i];
            if(ch=='(')
            st.push({ch,i});
            else if(ch==')'){
                if(!st.empty() && st.top().first=='(')
                st.pop();
                else
                st.push({ch,i});
            }
            else
            continue;
        }
        while(!st.empty()){
            s.erase(st.top().second,1);
            // cout<<st.top().first<<" "<<st.top().second<<" ";
            st.pop();
        }
        return s;
    }
};