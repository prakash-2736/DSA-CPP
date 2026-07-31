class Solution {
public:
    int minimumPushes(string word) {
        vector<int> count(26, 0);
        for (char c : word) {
            count[c - 'a']++;
        }

        sort(count.rbegin(), count.rend());

        int totalPushes = 0;
        for (int i = 0; i < 26; ++i) {
            int pushes = (i / 8) + 1;
            totalPushes += count[i] * pushes;
        }

        return totalPushes;
    }
};
