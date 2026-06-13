class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // unordered_set<char> st;

        // int l = 0;
        // int ans = 0;

        // for(int r = 0; r < s.size(); r++) {

        //     while(st.count(s[r])) {
        //         st.erase(s[l]);
        //         l++;
        //     }

        //     st.insert(s[r]);

        //     ans = max(ans, r - l + 1);
        // }

        // return ans;

        int l = 0;
        int r = 0;
        int n = s.length();
        int max_len = 0;

        vector<int> hash(256, -1);

        while (r < n) {

            if (hash[s[r]] != -1) {

                l = max(l, hash[s[r]] + 1);
            }

            max_len = max(max_len, r - l + 1);

            hash[s[r]] = r;
            r++;
        }
        return max_len;
    }
};
