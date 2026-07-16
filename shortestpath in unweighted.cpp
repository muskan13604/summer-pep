class Solution {
  public:
    int shortestPath(int V, vector<vector<int>> &edges, int src, int dest) {
        // Create adjacency list
        vector<vector<int>> adj(V);

        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);   // Remove this line if the graph is directed
        }

        vector<int> dist(V, -1);
        queue<int> q;

        q.push(src);
        dist[src] = 0;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            if (node == dest)
                return dist[node];

            for (int nei : adj[node]) {
                if (dist[nei] == -1) {
                    dist[nei] = dist[node] + 1;
                    q.push(nei);
                }
            }
        }

        return -1; // Destination not reachable
    }
};`