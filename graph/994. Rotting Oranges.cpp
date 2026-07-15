class Solution { 
public: 
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(); 
        int m = grid[0].size(); 
        
        // Queue stores pairs of {row, col}
        queue<pair<int, int>> q;
        int freshOranges = 0;
        
        // Step 1: Find all initial rotten oranges and count fresh ones
        for (int i = 0; i < n; i++) { 
            for (int j = 0; j < m; j++) { 
                if (grid[i][j] == 2) { 
                    q.push({i, j}); // Push coordinates of rotten orange
                } else if (grid[i][j] == 1) {
                    freshOranges++;
                }
            } 
        }
        
        // If there are no fresh oranges to rot, 0 minutes are needed
        if (freshOranges == 0) return 0;
        
        int time = 0;
        // Direction vectors for moving Up, Right, Down, Left
        int dRow[] = {-1, 0, 1, 0};
        int dCol[] = {0, 1, 0, -1};
        
        // Step 2: BFS layer by layer (Level Order Traversal)
        while (!q.empty()) { 
            int size = q.size();
            bool rottedAnyThisMinute = false;
            
            // Process all oranges turning rotten at the current minute
            for (int i = 0; i < size; i++) {
                auto [r, c] = q.front(); 
                q.pop(); 
                
                // Check all 4 neighboring directions
                for (int d = 0; d < 4; d++) {
                    int nRow = r + dRow[d];
                    int nCol = c + dCol[d];
                    
                    // If within bounds and neighbor is a fresh orange
                    if (nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && grid[nRow][nCol] == 1) {
                        grid[nRow][nCol] = 2; // Make it rotten
                        q.push({nRow, nCol}); // Add to queue for next minute
                        freshOranges--;       // Decrease fresh count
                        rottedAnyThisMinute = true;
                    }
                }
            }
            // Increment time only if at least one fresh orange was infected
            if (rottedAnyThisMinute) time++;
        } 
        
        // Step 3: If fresh oranges are still left, it's impossible to rot all
        return freshOranges == 0 ? time : -1; 
    } 
};
