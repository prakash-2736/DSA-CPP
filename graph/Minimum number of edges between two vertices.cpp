 
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            
            // If we reached the destination, return its distance
            if (curr == v) return dist[curr];
            
            // Check all neighboring nodes
            for (int neighbor : adj[curr]) {
                // If the neighbor hasn't been visited yet
                if (dist[neighbor] == -1) {
                    dist[neighbor] = dist[curr] + 1;
                    q.push(neighbor);
                }
            }
        }
