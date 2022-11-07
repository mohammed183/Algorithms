class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();

        if (n1 > n2) return findMedianSortedArrays(nums2, nums1);
        int ev = (n1+n2)%2;
        int med = (n1+n2+1)/2;
        int left = 0, right = n1;
        while (left <= right) {
            int mid1 = left + (right - left)/2;
            int mid2 = med - mid1;
            int l1 = mid1-1 > -1 ? nums1[mid1-1]:INT_MIN;
            int r1 = mid1 < n1 ? nums1[mid1]:INT_MAX;
            int l2 = mid2-1 > -1 ? nums2[mid2-1]:INT_MIN;
            int r2 = mid2 < n2 ? nums2[mid2]:INT_MAX;

            if (l1 <= r2 && l2 <= r1) {
                if (ev){
                    return max(l1,l2);
                }
                return (max(l1,l2)+min(r1,r2))/2.0;
            }
            else if (l1 > r2){
                right = mid1-1;
            }
            else {
                left = mid1+1;
            }
        }
        return -1;
    }
};
