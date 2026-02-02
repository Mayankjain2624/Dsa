class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        int c1=0,c2=0,c1f=0,c2f=0;
        for(int j=0;j<n;j++){
             if(c1f==0 && nums[j]!=c2){
                c1=nums[j];
                c1f=1;
             }
             else if(c2f==0 && nums[j]!=c1)
             {
                c2=nums[j];
                c2f=1;
             }
             else
             {
             if(nums[j]==c1)
             {
                c1f++;
             }
             else if(nums[j]==c2)
             {
                c2f++;
             }
             else
             {
                c1f--;
                c2f--;
             }
             }
        }
        c1f=0,c2f=0;
        vector<int>ans;
        for(int k=0;k<n;k++){
            if(nums[k]==c1)
            c1f++;
            else if(nums[k]==c2)
            c2f++;
        }
        if(c1f>(n/3))
        ans.push_back(c1);
        if(c2f>(n/3))
        ans.push_back(c2);
        return ans;

    }
};

