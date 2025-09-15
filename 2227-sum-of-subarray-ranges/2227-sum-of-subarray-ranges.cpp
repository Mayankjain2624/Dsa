class Solution {
public:
    long long subArrayRanges(vector<int>& arr) {
       int n = arr.size();
        stack<int> st;
        vector<int> nse(n), pse(n);
        for (int i = n - 1; i >= 0; i--) {
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
        for (int i = 0; i < n; i++) {
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
        // vector<int> nge(n), pge(n);
        long long int mini=0;
        long long int maxi=0;
        long long int l,r;
        for(int i=0;i<n;i++){
            l=i-pse[i];
            r=nse[i]-i;
            mini+=(l*r*arr[i]);
        }
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] <= arr[i]) {
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
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] < arr[i]) {
                st.pop();
            }
            if (st.empty()) {
                pse[i] = -1;
            } else
                pse[i] = st.top();
            st.push(i);
        }     
        for(int i=0;i<n;i++){
            l=i-pse[i];
            r=nse[i]-i;
            maxi+=(l*r*arr[i]);
        }
        return maxi-mini;
    }
};