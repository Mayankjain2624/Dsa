class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int n = letters.size();
        int l = 0;
        int r = n ;
        while (l < r) {
            int mid = (l + r) / 2;
            if (letters[mid] <= target)
               l=mid+1;
            else
                r=mid;
            cout<<l<<endl;
        }
        if(l<=n-1)
        return letters[l];
        else
        return letters[0];
    }
};