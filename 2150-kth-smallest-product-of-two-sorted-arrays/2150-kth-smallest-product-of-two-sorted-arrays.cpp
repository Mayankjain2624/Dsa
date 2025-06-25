class Solution {
public:
    long countproduct(vector<int>& nums1, vector<int>& nums2, long long  target) {
        long long count = 0;
        for (int& num1 : nums1) {
            if (num1 == 0 && target >= 0)
                count += nums2.size();
            else if (num1 > 0) {
                long long l = 0;
                long long r = nums2.size();
                while (l < r) {
                    long long mid = l + (r - l) / 2;
                    if (1LL * num1 * nums2[mid] <= target) {
                        l = mid + 1;
                    } else
                        r = mid;
                }
                count += l;
            } else {
                long long l = 0;
                long long r = nums2.size();
                while (l < r) {
                    long long mid = l + (r - l) / 2;
                    if (1LL * num1 * nums2[mid] <= target) {
                        r = mid;
                    } else
                        l = mid + 1;
                }
                count += nums2.size() - l;
            }
        }
        return count;
    }
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2,
                                 long long k) {
                                    sort(nums2.begin(),nums2.end());
        long long left = -10000000000;
        long long right = 10000000000;
        while (left < right) {
            long long mid = left + (right - left) / 2;
            cout << mid << endl;
            long long cp = countproduct(nums1, nums2, mid);
            if (cp < k) {
                left = mid + 1;
            } else
                right = mid;
            cout << cp << endl;
        }
        return left;
    }
};