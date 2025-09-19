class StockSpanner {
public:
    int i=0;
    stack<pair<int,int>>st;
    StockSpanner() {
    st.push({1e5+7,-1});
        
    }
    
    int next(int price) {
        while(!st.empty() && st.top().first<=price)
        st.pop();
        int ans=i-st.top().second;
        st.push({price,i});
        i++;
        return ans;

    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */