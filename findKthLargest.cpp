class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        unordered_map <int, int> mp;
        for (auto i : nums) {
            mp[i]++;
        }
        vector<pair<int,int>> v;
        for(auto i : mp) {
            v.push_back({i.first, i.second});
        }
        sort(v.begin(), v.end());
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
