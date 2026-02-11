class Solution {
  public:
    double minMaxDist(vector<int> &stations, int k) {
        // Code here
        int n=stations.size();
        double l=0.0,r=0;
        for(int i=1;i<n;i++){
           r=max(r,1.0*stations[i]-stations[i-1]);
        }
        // double ans=0;
        while(r-l>=1e-6){
            double mid=(l+r)/2.0;
            int sn=0;
            for(int i=1;i<n;i++){
                sn+=ceil((stations[i]-stations[i-1])/mid)-1;
            }
            if(sn<=k){
                // ans=mid;
                r=mid;
            }
            else
            l=mid;
        }
        return l;
    }
};