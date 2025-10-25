class Solution {
public:
   void func(int ind,int sum,int target,vector<int>&nums,vector<int>&sub,set<vector<int>>&ans){
       if(ind==nums.size())
       return;
       if(sum>target)
       return;
       if(sum==target)
       {
        ans.insert(sub);
        return;
       }
       sub.push_back(nums[ind]);
       func(ind+1,sum+nums[ind],target,nums,sub,ans);
       func(ind,sum+nums[ind],target,nums,sub,ans);
       sub.pop_back();
       func(ind+1,sum,target,nums,sub,ans);

   }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        set<vector<int>>ans;
        vector<int>sub;
        int sum=0;
        func(0,sum,target,candidates,sub,ans);
        vector<vector<int>>snd(ans.begin(),ans.end());
        return snd;
    }
};