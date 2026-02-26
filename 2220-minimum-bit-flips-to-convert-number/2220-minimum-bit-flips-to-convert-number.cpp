class Solution {
public:
    int minBitFlips(int start, int goal) {
        int news=start^goal;
        int count=0;
        while(news!=0){
           news=news&(news-1);
           count++;
        }
        return count;
    }
};