class Solution {
  public:
    int minTime(vector<int>& arr, int k) {
        // code here
        int n=arr.size();
        int l=*max_element(arr.begin(),arr.end());
        int r=accumulate(arr.begin(),arr.end(),0);
        int ans=0;
        while(l<=r){
            int mid=l+(r-l)/2;
            int npr=1;
            int cs=0;
            for(int i:arr){
                cs+=i;
                if(cs>mid){
                    cs=i;
                    npr++;
                }
            }
            if(npr<=k){
                ans=mid;
                r=mid-1;
            }
            else
            l=mid+1;
        }
        return ans;
    }
};