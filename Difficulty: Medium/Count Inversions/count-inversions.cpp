class Solution {
  public:
  int cnt=0;
    void merge(vector<int>&arr,int left,int mid,int right)
    {
        int l=left;
        int r=mid+1;
        int n1=mid-left+1;
        int n2=right-mid;
        vector<int>temp1(arr.begin()+left,arr.begin()+mid+1),
        temp2(arr.begin()+mid+1,arr.begin()+right+1);
        int i=0,j=0;
        int k=left;
        while(i<n1 && j<n2)
        {
            if(temp1[i]>temp2[j])
            {
                cnt+=(n1-i);
                arr[k]=temp2[j];
                j++;
            }
            else
            {
                arr[k]=temp1[i];
                i++;
            }
            k++;
        }
        while(i<n1){
            arr[k]=temp1[i];
            i++;
            k++;
        }
        while(j<n2){
            arr[k]=temp2[j];
            j++;
            k++;
        }
    }
    void mergeSort(vector<int>&arr,int left,int right){
        if(left>=right)
        return;
        int mid=left+(right-left)/2;
        mergeSort(arr,left,mid);
        mergeSort(arr,mid+1,right);
        merge(arr,left,mid,right);
    }
    int inversionCount(vector<int> &arr) {
        int n=arr.size();
           mergeSort(arr,0,n-1);
           return cnt;
      }
};