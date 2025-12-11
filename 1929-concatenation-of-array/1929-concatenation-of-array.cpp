class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int>v=nums;
        for(int i:v)
        nums.push_back(i);
        return nums;
    }
};