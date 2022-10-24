class Solution {
public:
    vector<int> A;
    int findmaxc(int low, int mid, int high) {
        int sum = 0;
        int ls = INT_MIN;
        for (int i = mid; i >= low; i--) {
            sum = sum + A[i];
            if (sum > ls)
                ls = sum;
        }
        sum = 0;
        int rs = INT_MIN;
        for (int i = mid; i <= high; i++) {
            sum = sum + A[i];
            if (sum > rs)
                rs = sum;
        }
        return max(ls + rs - A[mid],max(ls, rs));
    }
    int findmax(int low, int high) {
        if (high == low) return A[low];
        int mid =(low+high)/2;
        int a1, a2, a3;
        a1 = findmax(mid+1, high);
        a2 = findmax(low, mid);
        a3 = findmaxc(low, mid, high);
        return max(a1, max(a2, a3));
    }
    int maxSubArray(vector<int>& nums) {
        A = nums;
        int n = nums.size();
        int ans = findmax(0, n-1);
        return ans;
    }
};
