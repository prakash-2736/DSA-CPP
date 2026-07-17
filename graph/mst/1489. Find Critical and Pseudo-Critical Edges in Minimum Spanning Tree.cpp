class Solution {
public:

    // ---------------- Disjoint Set (Union Find) ----------------
    class DSU {
    public:
        vector<int> parent, rank;

        DSU(int n) {
            parent.resize(n);
            rank.resize(n, 0);

            for (int i = 0; i < n; i++)
                parent[i] = i;
        }

        int find(int x) {
            if (parent[x] == x)
                return x;

            return parent[x] = find(parent[x]);   // Path Compression
        }

        bool unite(int a, int b) {
            a = find(a);
            b = find(b);

            if (a == b)
                return false;

            if (rank[a] < rank[b])
                swap(a, b);

            parent[b] = a;

            if (rank[a] == rank[b])
                rank[a]++;

            return true;
        }
    };

    // Kruskal Function
    int mst(int n, vector<vector<int>>& edges, int block, int force) {

        DSU dsu(n);

        int weight = 0;
        int cnt = 0;

        // Force include one edge
        if (force != -1) {
            dsu.unite(edges[force][0], edges[force][1]);
            weight += edges[force][2];
            cnt++;
        }

        // Normal Kruskal
        for (int i = 0; i < edges.size(); i++) {

            if (i == block)
                continue;

            if (dsu.unite(edges[i][0], edges[i][1])) {
                weight += edges[i][2];
                cnt++;
            }
        }

        // Graph not connected
        if (cnt != n - 1)
            return INT_MAX;

        return weight;
    }

    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {

        int m = edges.size();

        // Store original index
        for (int i = 0; i < m; i++)
            edges[i].push_back(i);

        // Sort by weight
        sort(edges.begin(), edges.end(),
            [](vector<int>& a, vector<int>& b) {
                return a[2] < b[2];
            });

        // Original MST Weight
        int original = mst(n, edges, -1, -1);

        vector<int> critical;
        vector<int> pseudo;

        for (int i = 0; i < m; i++) {

            // Check Critical
            if (mst(n, edges, i, -1) > original) {
                critical.push_back(edges[i][3]);
            }

            // Check Pseudo Critical
            else if (mst(n, edges, -1, i) == original) {
                pseudo.push_back(edges[i][3]);
            }
        }

        return {critical, pseudo};
    }
};
