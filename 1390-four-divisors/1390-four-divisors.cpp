class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i = 0; i < n; i++){
            int num = nums[i];
            vector<int> v;
            v.push_back(1);
            v.push_back(num);
            int ct = 2;
            for(int i = 2; i <= num/2; i++){
                if(num % i == 0) {
                    ct++;
                    v.push_back(i);
                }
                if(ct > 4) break;
            }
            if(ct == 4){
                sum += (v[0] + v[1] + v[2] + v[3]);
            }
        }
        return sum;
    }
};