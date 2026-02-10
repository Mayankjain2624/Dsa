class Solution {
  public:
    int aggressiveCows(vector<int> &stalls, int k) {
        // code here
        int n=stalls.size();
        sort(stalls.begin(),stalls.end());
        int l=INT_MAX,r=stalls[n-1]-stalls[0];
        for(int i=1;i<n;i++){
            l=min(l,stalls[i]-stalls[i-1]);
        }
        int ans=0;
        while(l<=r){
            int mid=l+(r-l)/2;
            int lastpos=stalls[0];
            int ncp=1;
            for(int i=1;i<n;i++){
                if((stalls[i]-lastpos)>=mid){
                    ncp++;
                    lastpos=stalls[i];
                }
            }
            // cout<<mid<<" "<<ncp<<endl;
            if(ncp>=k){
                ans=mid;
                l=mid+1;
            }
            else
              r=mid-1;
        }
        return ans;
    }
};