class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        map <int, int> mp;   // Makes Worst case nlogn so not guaranteed O(n), however got accepted
        for (auto i : nums) {
            mp[i]++;
        }
        vector<pair<int,int>> v;
        for(auto i : mp) {
            v.push_back({i.first, i.second});
        }
        int n = v.size();
        for (int i = 1; i < n; i++) {
            v[i].second += v[i-1].second;
        }
        int ans = INT_MIN;
        int l = nums.size();
        k = l-k+1;
        for (int i = n-1; i > 0; i--) {
            if (k <= v[i].second && k > v[i-1].second) {
                ans = v[i].first;
                break;
            }
        }
        if (ans == INT_MIN) ans = v[0].first;
        return ans;
        
    }
};
// Another Solution
class Solution {
public:
    int partition(vector<int>& nums, int f, int l,int mid){
        int i=f; int j=f;
        while(j<=l){
            if(nums[j] <= mid){
                swap(nums[i],nums[j]);
                i++;j++;
            }else{
                j++;
            }
        }
        return i-1;
    }
    int helper(vector<int>& nums, int f, int l,int k){
        int piv = nums[l]; // Time exceed for mid and first element as worst case is n^2 (didn't use rand select as may lead to higher cost)
        int ind = partition(nums,f,l,piv);
        if(ind == k){
            return nums[pi];
        }else if(ind<k){
            return helper(nums,ind+1,l,k);
        }else{
            return helper(nums,f,ind-1,k);
        }
        return 0;
    }
    int findKthLargest(vector<int>& nums, int k) {
        int n=nums.size();
        k = n-k;
        int f = 0;
        int l = n-1;
        return helper(nums,f,l,k);
    }
};
