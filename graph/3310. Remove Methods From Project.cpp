class Solution {
public:
    vector<int> remainingMethods(int n, int k,
                                 vector<vector<int>>& invocations) {
        vector<vector<int>> adj(n);
        for (const auto& inv : invocations) {
            adj[inv[0]].push_back(inv[1]);
        }

        vector<bool> suspicious(n, false);
        auto mark_suspicious = [&](auto& self, int u) -> void {
            suspicious[u] = true;
            for (int v : adj[u]) {
                if (!suspicious[v]) {
                    self(self, v);
                }
            }
        };
        mark_suspicious(mark_suspicious, k);

        bool valid = true;
        for (const auto& inv : invocations) {
            int u = inv[0], v = inv[1];
            if (!suspicious[u] && suspicious[v]) {
                valid = false;
                break;
            }
        }

        vector<int> result;
        for (int i = 0; i < n; ++i) {
            if (valid && suspicious[i])
                continue;
            result.push_back(i);
        }
        return result;
    }
};
