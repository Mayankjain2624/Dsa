class Solution {
public:
    int maxSideLength(vector<vector<int>>&grid, int thre) {
        int n=grid.size();
        int m=grid[0].size();
        int ans=0;
        vector<vector<int>>col(n,vector<int>(m,0));
        vector<vector<int>>row(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            int curr=0;
            for(int j=0;j<m;j++){
                curr+=grid[i][j];
                row[i][j]+=curr;
            }
        }
        for(int j=0;j<m;j++){
            int curr=0;
            for(int i=0;i<n;i++){
                curr+=grid[i][j];
                col[i][j]=curr;
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int curr=min(m-j,n-i);
                int sum=0;
                for(int k=0;k<curr;k++){
                    sum+=row[i+k][curr+j-1] - ((j==0)?0:row[i+k][j-1]);
                }
                while(curr >0){

                    
                    if(sum<=thre){
                        ans=max(ans,curr);
                        break;
                    }
                    else{
                        sum-=row[i+curr-1][curr+j-1] - ((j==0)?0:row[i+curr-1][j-1]);
                        if(curr >1)sum-=col[curr+i-2][j+curr-1] - ( (i==0)?0:col[i-1][j+curr-1]);
                    } 
                    curr--;
                }
                
            }
        }
        return ans;
    }
};