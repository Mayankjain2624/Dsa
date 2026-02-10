class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        long long int r=0;
        for(int i:piles){
            r+=i;
        }
        long long int l=1;
        long long int ans=0;
        while(l<=r){
            long long int mid=l+(r-l)/2;
            long long int hn=0;
            for(long long int i:piles){
                hn+=ceil(i*1.0/mid);
            }
            if(hn<=h){
                ans=mid;
                r=mid-1;
            }
            else
            l=mid+1;

        }
        return ans;
    }
};