class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        // vector<long long int>d;
        map<long long int,long long int>mp;
        for(int i=0;i<nums.size();i++){
            //    d.push_back(i-nums[i]+1);
               mp[i-nums[i]+1]++;
        }
       long long  int n=nums.size();
       long long  int total=n*(n-1)/2;
        long long int gp=0;
        for(auto &it:mp){
            // cout<<it.first<<" "<<it.second<<endl;
           long long  int k=it.second;
            gp+=(k*(k-1))/2;
        }
        // cout<<total-gp<<endl;
        return total-gp;
    }
   
};