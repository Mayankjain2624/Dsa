class Solution {
  public:
    vector<int> find3Numbers(vector<int> &arr) {
        // Code here
        int n=arr.size();
        if(n<3)
        return {};
        vector<int>left(n),right(n);
        left[0]=arr[0];
        right[n-1]=arr[n-1];
        for(int i=1;i<n;i++){
            left[i]=min(left[i-1],arr[i-1]);
        }
        for(int i=n-2;i>=0;i--){
            right[i]=max(right[i+1],arr[i+1]);
        }
        for(int i=1;i<n;i++){
            if(left[i]<arr[i] && arr[i]<right[i]){
                return {left[i],arr[i],right[i]};
            }
        }
        return {};
    }
};