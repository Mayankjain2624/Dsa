class Solution {
public:
    vector<int> cycleLengthQueries(int n, vector<vector<int>>& queries) {
        vector<int>ans;
        for(auto &it:queries){
            int a=it[0];
            int b=it[1];
            int cnt=0;
            while(a!=b)
            {
              if(a>b)
              a/=2;
              else
              b/=2;
              cnt++;
            }
            // int sa=log2(it[0])+log2(it[1])-log2(a)+1;
            ans.push_back(cnt+1);
        }
        return ans;
    }
};