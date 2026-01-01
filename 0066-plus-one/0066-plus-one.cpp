class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 0;
        int n = digits.size();
        reverse(digits.begin(), digits.end());
        if (digits[0] == 9) {
            digits[0] = 0;
            carry = 1;
        }
        else
        digits[0]++;
        for (int i = 1; i < n; i++) {
            if (carry == 1) {
                if(digits[i]==9){
                digits[i] = 0;
                carry = 1;
                }else
                {
                digits[i]++;
                carry=0;
                }
            }
            else
            break;
        }
        if(carry==1){
            digits.push_back(1);
        }
         reverse(digits.begin(), digits.end());
         return digits;
    }
};