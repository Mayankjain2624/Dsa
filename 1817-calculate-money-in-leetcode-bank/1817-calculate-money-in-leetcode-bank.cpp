class Solution {
public:
    int totalMoney(int n) {
        int sum=0;
        int prev=0;
        while(n>0){
            int x=min(n,7)+prev;
            
            sum+=(x*(x+1))/2-(prev*(prev+1))/2;
            n-=min(n,7);
            prev++;
            cout<<sum<<endl;
        }
        return sum;
    }
};