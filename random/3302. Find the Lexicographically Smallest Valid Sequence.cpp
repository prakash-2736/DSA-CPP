class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();

        vector<int> last_match(m, -1);

        int j = m - 1;
        for (int i = n - 1; i >= 0 && j >= 0; --i) {
            if (word1[i] == word2[j]) {
                last_match[j] = i;
                j--;
            }
        }

        vector<int> ans(m);
        bool can_skip = true; 
        j = 0;              

        for (int i = 0; i < n; ++i) {
            if (j == m)
                break;

            if (word1[i] == word2[j]) {
                ans[j] = i;
                j++;
            }
            else if (can_skip && (j == m - 1 || i < last_match[j + 1])) {
                can_skip = false; 
                ans[j] = i;
                j++;
            }
        }
        return (j == m) ? ans : vector<int>();
    }
};
