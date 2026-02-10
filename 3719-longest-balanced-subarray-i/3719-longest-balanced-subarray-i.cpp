class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        
        int n = nums.size();

        if(n==1)
          return 1;
    
        int maxi=0;
        for(int i=0;i<n;i++){
            int odd=0, even=0;
            set<int> s;
            for(int j=i;j<n;j++){
                if(nums[j]%2!=0 && s.find(nums[j])==s.end()){
                    s.insert(nums[j]);
                    odd++;
                }
                else if(nums[j]%2==0 && s.find(nums[j])==s.end()){
                    s.insert(nums[j]);
                    even++;
                }
                
                if(odd==even)
                  maxi=max(maxi,j-i+1);
            }
        }
        return maxi;
    }
};