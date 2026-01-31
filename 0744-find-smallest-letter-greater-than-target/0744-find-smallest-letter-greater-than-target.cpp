class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int n=letters.size();
        int l=0,r=n-1,ans=1e9;
        while(l<=r){
            int mid=(l+r)/2;
            if(letters[mid]<=target)
            {
                l=mid+1;
            }
            else
            {
                ans=min(mid,ans);
                r=mid-1;
            }
        }
        if(ans==1e9)
        return letters[0];
        else
        return letters[ans];
    }
};