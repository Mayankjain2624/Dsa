class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int n=bank.size();
        int m=bank[0].size();
        vector<int>nos(n);
        for(int i=0;i<n;i++){
            int count=0;
            for(int j=0;j<m;j++){
                if(bank[i][j]=='1')
                count++;
            }
            nos[i]=count;
        }
        int sum=0;
        int prev=nos[0];
        for(int i=1;i<n;i++){
            sum+=(nos[i]*prev);
            if(nos[i]!=0)
            prev=nos[i];
        }
        return sum;
    }
};