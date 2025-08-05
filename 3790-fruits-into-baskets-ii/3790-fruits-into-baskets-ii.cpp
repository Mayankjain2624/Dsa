class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        // sort(fruits.begin(),fruits.end());
        // sort(baskets.begin(),baskets.end());
        // int start=0;
        int ans=0;
        int n=fruits.size();
        for(int i=0;i<n;i++){
            int flag=0;
            for(int j=0;j<n;j++){
                if(baskets[j]!=-1 && baskets[j]>=fruits[i]){
                    baskets[j]=-1;
                    flag=1;
                    break;
                }
            }
            if(!flag)
            ans++;
        }
        return ans;
    }
};