class Solution {
public:
    static const int MOD = 1e9 + 7;
    int interleaveCharacters(string word1, string word2, string target) {
        int n1 = word1.size();
        int n2 = word2.size();

        int l = target.size();

        vector<vector<long long>> dp(n1 + 1, vector<long long>(n2 + 1, 0));
        dp[0][0] = 1;

        for (int i = 0; i < l; i++) {

            char c = target[i];

            vector<vector<long long>> newdp(n1 + 1,
                                            vector<long long>(n2 + 1, 0));

            for (int i2 = 0; i2 <= n2; i2++) {

                vector<long long> pref(n1 + 2, 0);

                for (int i1 = 0; i1 <= n1; i1++) {
                    pref[i1 + 1] = (pref[i1] + dp[i1][i2]) % MOD;
                }

                for (int i1 = 1; i1 <= n1; i1++) {
                    if (word1[i1 - 1] == c) {
                        newdp[i1][i2] = (newdp[i1][i2] + pref[i1]) % MOD;
                    }
                }
            }

            for (int i1 = 0; i1 <= n1; i1++) {

                vector<long long> pref(n2 + 2, 0);

                for (int i2 = 0; i2 <= n2; i2++) {
                    pref[i2 + 1] = (pref[i2] + dp[i1][i2]) % MOD;
                }

                for (int i2 = 1; i2 <= n2; i2++) {
                    if (word2[i2 - 1] == c) {
                        newdp[i1][i2] = (newdp[i1][i2] + pref[i2]) % MOD;
                    }
                }
            }

            dp = move(newdp);
        }

        long long ans = 0;

        for (int i1 = 1; i1 <= n1; i1++) {
            for (int i2 = 1; i2 <= n2; i2++) {

                ans = (ans + dp[i1][i2]) % MOD;
            }
        }

        return (int)ans;
    }
};
