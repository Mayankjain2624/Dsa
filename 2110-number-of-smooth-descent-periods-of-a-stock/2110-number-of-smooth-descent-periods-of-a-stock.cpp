class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        int l=0;
        int r=1;
        int n=prices.size();
        long long int ans=0;
        while(r<n){
            if(prices[r]==(prices[r-1]-1))
            {
                r++;
            }
            else
            {
                long long int k=r-l;
                ans+=(k*(k+1))/2;
                l=r;
                r++;
            }
        }
        long long int k=r-l;
                ans+=(k*(k+1))/2;
        return ans;
    }
};