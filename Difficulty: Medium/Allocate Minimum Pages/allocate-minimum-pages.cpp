class Solution {
  public:
    int findPages(vector<int> &arr, int k) {
        // code here
        int l=*max_element(arr.begin(),arr.end());
        int r=accumulate(arr.begin(),arr.end(),0);
        int ans=-1;
        if(arr.size()<k)
        return -1;
        while(l<=r){
            int mid=l+(r-l)/2;
            int ns=1;
            int cs=0;
            for(int i:arr){
                cs+=i;
                if(cs>mid){
                    ns++;
                    cs=i;
                }
            }
            // cout<<mid<<" "<<ns<<endl;
            if(ns<=k){
                ans=mid;
                r=mid-1;
            }
            else
            l=mid+1;
            
        }
        return ans;
    }
};