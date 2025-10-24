class Solution {
public:
    bool checknumber(int x){
        unordered_map <int,int> res;
        while(x>0){
            int temp=x%10;
            if(temp>6) return false;
            res[temp]++;
            x=x/10;
        }
        for (auto num:res){
            if(num.first!=num.second){
                return false;
            }
        }
        return true;
    }
    int nextBeautifulNumber(int n) {
        int num=n+1;
        while(true){
            if(checknumber(num)){
                return num;
            }
            num++;  
        }
    }
};