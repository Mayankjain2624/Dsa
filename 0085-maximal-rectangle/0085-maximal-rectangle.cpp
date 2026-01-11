class Solution {
public:
    vector<vector<int>> findpns(vector<int>v){
        int m=v.size();
        vector<vector<int>>ans(2,vector<int>(m,0));
        stack<int>st;
        for(int i=0;i<m;i++){
            while(!st.empty() && v[st.top()]>=v[i])
            st.pop();
            if(!st.empty())
            ans[0][i]=st.top();
            else
            ans[0][i]=-1;
            st.push(i);
        }
        stack<int>st1;
        for(int i=m-1;i>=0;i--){
            while(!st1.empty() && v[st1.top()]>=v[i])
            st1.pop();
            if(!st1.empty())
            ans[1][i]=st1.top();
            else
            ans[1][i]=m;
            st1.push(i);
        }
      return ans;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int maxArea=0;
        vector<int>prev(m,0);
        for(int i=0;i<n;i++){
            vector<int>curr(m);
            for(int j=0;j<m;j++){
               if(matrix[i][j]=='1')
               curr[j]=prev[j]+1;
               else
               curr[j]=0;
            }
               vector<vector<int>>psns=findpns(curr);
            //    for(auto &it:psns){
            //     for(int i:it)
            //     cout<<i<<" ";
            //     cout<<endl;
            //    }
            //    for(int i:curr)
            //    cout<<i<<" ";
            //    cout<<endl;
            for(int i=0;i<m;i++){
                int area=(psns[1][i]-psns[0][i]-1)*curr[i];
                // cout<<area<<endl;
                maxArea=max(maxArea,area);
            }
            prev=curr;
        }
        return maxArea;
    }
};