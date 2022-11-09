class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = p.size();
        int l = s.size();
        vector<int> v;
        vector<int> cnt(26,0);
        vector<int> pcnt(26,0);
        if (n > l) return v;
        for (int i = 0; i < n; i++) {
            cnt[s[i]-'a']++;
            pcnt[p[i]-'a']++;
        }
        if (cnt == pcnt) v.push_back(0);
        for (int i = n; i < l; i++){
            cnt[s[i-n]-'a']--;
            cnt[s[i]-'a']++;
            if (cnt == pcnt) v.push_back(i-n+1);
        }
        return v;
    }
};
