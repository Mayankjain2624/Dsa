class Solution {
public:
    int kthGrammar(int n, int k) {
        int ans=0;
       long long int left=1;
       long long int right=1<<(n-1);
        for(int i=0;i<n;i++){
            long long int mid=(left+right)/2;
            if(k<=mid){
                right=mid;
            }
            else
            {
                left=mid+1;
                ans=!ans;
            }
        }
    return ans;
    }
};