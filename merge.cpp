class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m-1, j = n-1, k = n+m-1;
        while (i > -1) {
            if (j > -1 && nums1[i]  < nums2[j]) nums1[k--] = nums2[j--];
            else nums1[k--] = nums1[i--];
        }
        while (j > -1) nums1[k--] = nums2[j--];
    }
};
