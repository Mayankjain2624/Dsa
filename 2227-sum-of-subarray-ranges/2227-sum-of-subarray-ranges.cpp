class Solution {
public:
    long long subArrayRanges(vector<int>& arr) {
       long long int n = arr.size();
        stack<long long int> st;
        vector<long long int> nse(n), pse(n);
        for (long long int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            if (st.empty()) {
                nse[i] = n;
            } else
                nse[i] = st.top();
            st.push(i);
        }
        while (!st.empty()) {
            st.pop();
        }
        for (long long int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            if (st.empty()) {
                pse[i] = -1;
            } else
                pse[i] = st.top();
            st.push(i);
        }
         while (!st.empty()) {
            st.pop();
        }
        vector<long long int> nge(n), pge(n);
        for (long long int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] <= arr[i]) {
                st.pop();
            }
            if (st.empty()) {
                nge[i] = n;
            } else
                nge[i] = st.top();
            st.push(i);
        }
        while (!st.empty()) {
            st.pop();
        }
        for (long long int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] < arr[i]) {
                st.pop();
            }
            if (st.empty()) {
                pge[i] = -1;
            } else
                pge[i] = st.top();
            st.push(i);
        }
        long long int mini=0;
        long long int maxi=0;
        for(long long int i=0;i<n;i++){
            long long int l=i-pse[i];
            long long int r=nse[i]-i;
            mini+=(l*r*arr[i]);
        }
        for(long long int i=0;i<n;i++){
            long long int l=i-pge[i];
            long long int r=nge[i]-i;
            maxi+=(l*r*arr[i]);
        }
        // cout<<maxi<<" "<<mini<<endl;
        // for(long long int i:nse)
        // cout<<i<<" ";
        // cout<<endl;
        // for(long long int i:pse)
        // cout<<i<<" ";
        // cout<<endl;
        // for(long long int i:nge)
        // cout<<i<<" ";
        // cout<<endl;
        // for(long long int i:pge)
        // cout<<i<<" ";
        // cout<<endl;
        return maxi-mini;
    }
};