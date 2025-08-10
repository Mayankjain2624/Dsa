class Solution {
public:
    bool reorderedPowerOf2(int n) {
        unordered_map<int,int> mpp;
        while(n){
            mpp[n%10]++;
            n=n/10;
        }
        for(int i=0;i<32;i++){
            int num=1<<i;
            while(num){
                mpp[num%10]--;
                num=num/10;
            }
            bool ans=true;
            for(auto it:mpp){
                if(it.second!=0) ans=false;
            }
            if(ans) return ans;
            num=1<<i;
            while(num){
                mpp[num%10]++;
                num=num/10;
            }
        }
        return false;
    }
};