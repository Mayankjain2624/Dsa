class Solution {
public:
    int p1 = 0, p2 = 0;
    int getmin(vector<int> nums1, vector<int>& nums2) {
        if (p1 < nums1.size() && p2 < nums2.size()) {
            if (nums1[p1] <= nums2[p2])
                return nums1[p1++];
            if (nums2[p2] < nums1[p1])
                return nums2[p2++];
        } else if (p1 < nums1.size())
            return nums1[p1++];
        else if (p2 < nums2.size())
            return nums2[p2++];
            return -1;
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        int x=(n1+n2+1)/2;
        double y;
        while(x--){
            y=1.0*getmin(nums1,nums2);
        }
        if ((n1 + n2) % 2 == 0) {
            y+=1.0*getmin(nums1,nums2);
            y/=2.0;
        } 
        return y;
    }
};