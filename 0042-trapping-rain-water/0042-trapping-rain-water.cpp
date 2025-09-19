class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int>left(n),right(n);
        int ml=-1,mr=-1;
        for(int i=0;i<n;i++){
             ml=max(ml,height[i]);
             if(ml>height[i])
             left[i]=ml;
             else
             left[i]=-1;
        }
        for(int i=n-1;i>=0;i--){
             mr=max(mr,height[i]);
             if(mr>height[i])
             right[i]=mr;
             else
             right[i]=-1;
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(left[i]!=-1 && right[i]!=-1)
            ans+=(min(left[i],right[i])-height[i]);
        }
       return ans;
    }   
};