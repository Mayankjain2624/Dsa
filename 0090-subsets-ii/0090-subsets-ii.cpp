class Solution {
public:
   void func(int ind,vector<int>&nums,vector<int>&sub,set<vector<int>>&ans){
       if(ind==nums.size())
       {
        ans.insert(sub);
       return;
       }
       sub.push_back(nums[ind]);
       func(ind+1,nums,sub,ans);
    //    func(ind,sum+nums[ind],target,nums,sub,ans);
       sub.pop_back();
    //    ind++;
    //    while(ind<nums.size() && nums[ind]==nums[ind-1])
    //    ind++;
       func(ind+1,nums,sub,ans);

   }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
         set<vector<int>>ans;
        vector<int>sub;
        int sum=0;
        sort(nums.begin(),nums.end());
        func(0,nums,sub,ans);
        vector<vector<int>>snd(ans.begin(),ans.end());
        return snd;
    }
};