class Solution {
public:
long long int mod=1e9+7;
    int sumSubarrayMins(vector<int>& arr) {
         
          long long int n=arr.size();
          stack<long long int>st;
          vector<long long int>nse(n),pse(n);
          for(long long int i=n-1;i>=0;i--){
             while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
             }
             if(st.empty()){
                nse[i]=n;
             }
             else
             nse[i]=st.top();
             st.push(i);
          }
          while (!st.empty()) {
        st.pop(); 
    }
          for(long long int i=0;i<n;i++){
             while(!st.empty() && arr[st.top()]>arr[i]){
                st.pop();
             }
             if(st.empty()){
                pse[i]=-1;
             }
             else
             pse[i]=st.top();
             st.push(i);
          }
        //   for(long long int i:nse)
        //   cout<<i<<" ";
        //   cout<<endl;
        //   for(long long int i:pse)
        //   cout<<i<<" ";
        //   cout<<endl;
          vector<long long int>contri(n,0);
          long long int sum=0;
          for(long long int i=0;i<n;i++){
              long long int l=i-pse[i];
              long long int r=nse[i]-i;
             sum=(sum+(arr[i]*l*r)%mod)%mod;
          }
        //   for(long long int i:contri)
        //   cout<<i <<" ";
        //   cout<<endl;
          return (int)sum;
    }
};