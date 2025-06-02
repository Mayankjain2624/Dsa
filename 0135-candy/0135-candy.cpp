class Solution {
public:
    int candy(vector<int>& a) {
        int n=a.size();
      int left[20000]={0};
    //   int right[20000]={0};
      left[0]=1;
      for(int i=1;i<n;i++){
        if(a[i]>a[i-1])
        left[i]=left[i-1]+1;
        else
        left[i]=1;
      }
      int right=1;
      int sum=max(1,left[n-1]);
      int curr=1;
      for(int i=n-2;i>=0;i--){
        if(a[i]>a[i+1])
        {
              right=right+1;
              curr=right;
        // right[i]=right[i+1]+1;
        }
        else
        {
        curr=1;
        right=1;
        }
        sum+=max(curr,left[i]);

      }
      return sum;
    }
};