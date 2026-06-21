class Solution {
public:
    int characterReplacement(string s, int k) {

        int l = 0;
        int r = 0;
        int n = s.length();
        unordered_map<int, int> mp;
        int ans = 0, maxFreq = 0;
        while (r < n) {
            mp[s[r]]++;
            maxFreq = max(maxFreq, mp[s[r]]);

            while ((r - l + 1) - maxFreq > k) {

                mp[s[l]]--;
                l++;
            }

            ans = max(ans, r - l + 1);

            r++;
        }
        return ans;
    }
};
