class Solution {
public: 
   void func(int ind,vector<int>&nums,vector<int>&sub,vector<vector<int>>&ans){
    if(ind==nums.size()){
         ans.push_back(sub);
         return;
    }
    sub.push_back(nums[ind]);
    func(ind+1,nums,sub,ans);
    sub.pop_back();
    func(ind+1,nums,sub,ans);
   }



    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>sub;
        func(0,nums,sub,ans);
        return ans;
    }
};