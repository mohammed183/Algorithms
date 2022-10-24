class Solution {
public:
    int maxAr(vector<int>& nums, int l, int r) {
        if(r == l) return l;
        int mid = l + (r-l)/2;
        int m1 = maxAr(nums, l , mid);
        int m2 = maxAr(nums, mid+1, r);
        return nums[m1]>nums[m2]?m1:m2;
    }
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int ans = maxAr(nums, 0, n-1);
        return ans;
    }
};
