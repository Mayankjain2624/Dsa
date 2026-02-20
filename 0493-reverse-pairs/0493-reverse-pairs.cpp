class Solution {
public:
int cnt=0;
    void merge(vector<int>&nums,int left,int mid,int right){
        int n1=mid-left+1;
        int n2=right-mid;
        vector<int>t1(nums.begin()+left,nums.begin()+mid+1),
        t2(nums.begin()+mid+1,nums.begin()+right+1);
         int j=0;
         int i=0;
        while(i<n1 && j<n2){
                if((long long)t1[i]>(2LL*(long long )t2[j])){
                    cnt+=(n1-i);
                    j++;
              }
              else
              {
                i++;
              }
        }
        i=0,j=0;
        int k=left;
        while(i<n1 && j<n2){
              if(t1[i]>t2[j]){
                nums[k]=t2[j];
                j++;
              }
              else
              {
                nums[k]=t1[i];
                i++;
              }
                k++;
        }
        while(i<n1){
            nums[k]=t1[i];
            i++;
            k++;
        }
        while(j<n2){
            nums[k]=t2[j];
            j++;
            k++;
        }
    }
    void mergeSort(vector<int>&nums,int left,int right){
        if(left>=right)
        return;
        int mid=left+(right-left)/2;
        mergeSort(nums,left,mid);
        mergeSort(nums,mid+1,right);
        merge(nums,left,mid,right);
    }
    int reversePairs(vector<int>& nums) {
        int n=nums.size();
        mergeSort(nums,0,n-1);
        // for(int i:nums){
        //     cout<<i<<" ";
        // }
        return cnt;
    }
};